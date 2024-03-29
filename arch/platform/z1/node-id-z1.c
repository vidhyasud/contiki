/*
 * Copyright (c) 2006, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 */

/**
 * \file
 *         Utility to store a node id in the external flash
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#include "contiki.h"
#include "sys/node-id.h"
#include "dev/xmem.h"
#include <string.h>

unsigned char node_mac[8];
unsigned short node_loc_x = 0;
unsigned short node_loc_y = 0;
unsigned short pl;


/*---------------------------------------------------------------------------*/
void
node_id_z1_restore(void)
{
  unsigned char buf[12];
  xmem_pread(buf, 12, NODE_ID_XMEM_OFFSET);
  if(buf[0] == 0xad &&
     buf[1] == 0xde) {
    node_id = (buf[2] << 8) | buf[3];
    memcpy(node_mac, &buf[4], 8);
  } else {
    node_id = 0;
  }
}
/*---------------------------------------------------------------------------*/
void
node_id_z1_burn(unsigned short id)
{
  unsigned char buf[12];
  memset(buf, 0, sizeof(buf));
  buf[0] = 0xad;
  buf[1] = 0xde;
  buf[2] = id >> 8;
  buf[3] = id & 0xff;
  xmem_erase(XMEM_ERASE_UNIT_SIZE, NODE_ID_XMEM_OFFSET);
  xmem_pwrite(buf, 12, NODE_ID_XMEM_OFFSET);
}
/*---------------------------------------------------------------------------*/
