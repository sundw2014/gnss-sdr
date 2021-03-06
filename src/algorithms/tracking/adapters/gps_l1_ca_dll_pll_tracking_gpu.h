/*!
 * \file gps_l1_ca_dll_pll_tracking_gpu.h
 * \brief Implementation of an adapter of a DLL+PLL tracking loop block using GPU accelerated functions
 * for GPS L1 C/A to a TrackingInterface
 * \author Javier Arribas, 2015. jarribas(at)cttc.es
 *
 * Code DLL + carrier PLL according to the algorithms described in:
 * K.Borre, D.M.Akos, N.Bertelsen, P.Rinder, and S.H.Jensen,
 * A Software-Defined GPS and Galileo Receiver. A Single-Frequency
 * Approach, Birkha user, 2007
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2015  (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software defined Global Navigation
 *          Satellite Systems receiver
 *
 * This file is part of GNSS-SDR.
 *
 * GNSS-SDR is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GNSS-SDR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNSS-SDR. If not, see <http://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------
 */

#ifndef GNSS_SDR_GPS_L1_CA_DLL_PLL_TRACKING_GPU_H_
#define GNSS_SDR_GPS_L1_CA_DLL_PLL_TRACKING_GPU_H_

#include <string>
#include <gnuradio/msg_queue.h>
#include "tracking_interface.h"
#include "gps_l1_ca_dll_pll_tracking_gpu_cc.h"


class ConfigurationInterface;

/*!
 * \brief This class implements a code DLL + carrier PLL tracking loop using GPU accelerated functions
 */
class GpsL1CaDllPllTrackingGPU : public TrackingInterface
{
public:
  GpsL1CaDllPllTrackingGPU(ConfigurationInterface* configuration,
            std::string role,
            unsigned int in_streams,
            unsigned int out_streams,
            boost::shared_ptr<gr::msg_queue> queue);

    virtual ~GpsL1CaDllPllTrackingGPU();

    std::string role()
    {
        return role_;
    }

    //! Returns "GPS_L1_CA_DLL_PLL_Tracking_GPU"
    std::string implementation()
    {
        return "GPS_L1_CA_DLL_PLL_Tracking_GPU";
    }
    size_t item_size()
    {
        return item_size_;
    }

    void connect(gr::top_block_sptr top_block);
    void disconnect(gr::top_block_sptr top_block);
    gr::basic_block_sptr get_left_block();
    gr::basic_block_sptr get_right_block();


    /*!
     * \brief Set tracking channel unique ID
     */
    void set_channel(unsigned int channel);

    /*!
     * \brief Set acquisition/tracking common Gnss_Synchro object pointer
     * to efficiently exchange synchronization data between acquisition and tracking blocks
     */
    void set_gnss_synchro(Gnss_Synchro* p_gnss_synchro);

    /*!
     * \brief Set tracking channel internal queue
     */
    void set_channel_queue(concurrent_queue<int> *channel_internal_queue);

    void start_tracking();

private:
    gps_l1_ca_dll_pll_tracking_gpu_cc_sptr tracking_;
    size_t item_size_;
    unsigned int channel_;
    std::string role_;
    unsigned int in_streams_;
    unsigned int out_streams_;
    boost::shared_ptr<gr::msg_queue> queue_;
    concurrent_queue<int> *channel_internal_queue_;
};

#endif // GNSS_SDR_GPS_L1_CA_DLL_PLL_TRACKING_GPU_H_
