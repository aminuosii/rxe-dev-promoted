#ifndef RXE_DEBUG_H
#define RXE_DEBUG_H

#include "rxe.h"
#include "rxe_loc.h"
#include "rxe_queue.h"
// 打印函数的声明  
void print_rxe_send_wqe(const rxe_send_wqe *wqe);  
void print_rxe_send_wr(const rxe_send_wr *wr);  
void print_rxe_av(const rxe_av *av);  
void print_rxe_dma_info(const rxe_dma_info *dma);
const char* rxe_wr_mask_to_str(enum rxe_wr_mask mask);
void print_rxe_pkt_info(const struct rxe_pkt_info *pkt)

#endif /* RXE_HDR_H */