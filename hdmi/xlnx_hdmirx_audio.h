/*
 * Xilinx ALSA SoC HDMI audio capture support
 *
 * Copyright (C) 2017-2018 Xilinx, Inc.
 *
 * Author: Maruthi Srinivas Bayyavarapu <maruthis@xilinx.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __XILINX_HDMI_RX_AUD_H__
#define __XILINX_HDMI_RX_AUD_H__

struct xlnx_hdmirx_audio_data *hdmirx_get_audio_data(struct device *dev);
int hdmirx_register_aud_dev(struct device *dev);
void hdmirx_unregister_aud_dev(struct device *dev);
void __iomem *hdmirx_parse_aud_dt(struct device *dev);
u32 hdmirx_audio_startup(struct device *dev);
void hdmirx_audio_shutdown(struct device *dev);

/*
 * struct audio_params - audio stream parameters
 * @srate: sampling rate
 * @sig_bits: significant bits in container
 * @channels: number of channels
 */
struct audio_params {
	u32 srate;
	u32 sig_bits;
	u32 channels;
};

struct xlnx_hdmirx_audio_data {
	void __iomem *aes_base;
	struct audio_params *params;
};
#endif /* __XILINX_HDMI_RX_AUD_H__ */