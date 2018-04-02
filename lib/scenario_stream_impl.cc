/* -*- c++ -*- */
/* 
 * Copyright 2018 gr-djilink author.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "scenario_stream_impl.h"


using namespace DJI::OSDK; 


namespace gr {
  namespace djilink {

    scenario_stream::sptr
    scenario_stream::make()
    {
      return gnuradio::get_initial_sptr
        (new scenario_stream_impl());
    }

    /*
     * The private constructor
     */
    scenario_stream_impl::scenario_stream_impl()
      : gr::sync_block("scenario_stream",
              gr::io_signature::make(1, 1, sizeof(int)),
              gr::io_signature::make(0, 0, 0))
    {
      	std::cout << "Hello from scenario_stream_impl" << std::endl;

        char timeoutString[] = "/home/sami/down/gr-djilink/lib/UserConfig.txt";
        char *argv[] = { timeoutString, timeoutString, timeoutString}; // WTF?

        LinuxSetup linuxEnvironment(2, argv); 
        vehicle = linuxEnvironment.getVehicle();
    }

    /*
     * Our virtual destructor.
     */
    scenario_stream_impl::~scenario_stream_impl()
    {
    }

    int
    scenario_stream_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const int *in = (const int *) input_items[0];

      if (in[0] == 42) {
        char timeoutString[] = "/home/sami/down/gr-djilink/lib/UserConfig.txt";
        char *argv[] = { timeoutString, timeoutString, timeoutString}; // WTF?

        LinuxSetup linuxEnvironment(2, argv); 
        vehicle = linuxEnvironment.getVehicle();

        getBroadcastData(vehicle, 1);
      }

      // tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (noutput_items);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace djilink */
} /* namespace gr */

