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

#ifndef INCLUDED_DJILINK_SCENARIO_STREAM_IMPL_H
#define INCLUDED_DJILINK_SCENARIO_STREAM_IMPL_H

#include <djilink/scenario_stream.h>


#include <iostream>
//#include <dji_vehicle.hpp> // TODO remove or adapt
//#include "djiTools/flight_control_sample.hpp"

#include <iostream>
#include "djiTools/dji_vehicle.hpp" // TODO remove or adapt
#include "djiTools/flight_control_sample.hpp"
#include "djiTools/telemetry_sample.hpp"


using namespace DJI::OSDK; 

namespace gr {
  namespace djilink {

    class scenario_stream_impl : public scenario_stream
    {
    Vehicle *vehicle;
     private:
      // Nothing to declare in this block.

     public:
      scenario_stream_impl();
      ~scenario_stream_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace djilink
} // namespace gr

#endif /* INCLUDED_DJILINK_SCENARIO_STREAM_IMPL_H */

