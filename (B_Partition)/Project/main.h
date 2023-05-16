#ifndef __MAIN_H
#define __MAIN_H

#include "stdint.h"
#include "fmc.h"

/*
 * GD32 RAM	ROM  bank0_size bank1_size
 * 		64k	512k 	2k			4k
 */

#define GD32_RAM_SADDR		0x20000000
#define GD32_RAM_EADDR		GD32_RAM_SADDR + GD32_RAM_SIZE - 1
#define GD32_RAM_SIZE		64*1024

#define GD32_FLASH_SADDR	0x08000000										//FLASH起始地址
#define GD32_PAGE_SIZE		Flash_Page_Size_Bank0							//扇区大小
#define GD32_PAGE_NUM		256												//总扇区个数
#define	GD32_B_PAGE_NUM		10												//B区扇区个数
#define GD32_A_PAGE_NUM		GD32_PAGE_NUM - GD32_B_PAGE_NUM					//A区扇区个数
#define GD32_A_SPAGE		GD32_B_PAGE_NUM									//A区起始扇区编号
#define GD32_A_SADDR		GD32_FLASH_SADDR + GD32_A_SPAGE*GD32_PAGE_SIZE	//A区起始地址

#define OTA_SET_FLAG		0x01020304 //目前存在大小端问题

/* uint16_t 大小端互换 */
#define BigLittleSwap16(A)  ((((uint16_t)(A) & 0xff00) >> 8) | \
							(((uint16_t)(A) & 0x00ff) << 8))
 
/* uint32_t 大小端互换 */
#define BigLittleSwap32(A)  ((((uint32_t)(A) & 0xff000000) >> 24) | \
							(((uint32_t)(A) & 0x00ff0000) >> 8) | \
							(((uint32_t)(A) & 0x0000ff00) << 8) | \
							(((uint32_t)(A) & 0x000000ff) << 24))


typedef struct{
	uint32_t OTA_flag;
	/* 0号成员固定为OTA的大小 */
	uint32_t Firelen[11];
}OTA_InfoCB;
#define OTA_InfoCB_SIZE	sizeof(OTA_InfoCB)

typedef struct{
	uint8_t Updata_buff[GD32_PAGE_SIZE];
	uint32_t w25q64;
}UpDataA_CB;
#define UPDATAA_CB_SIZE	sizeof(UpDataA_CB)

extern OTA_InfoCB OTA_Info;
extern UpDataA_CB UpdataA;

#endif /* __MAIN_H */

