#include <stdio.h>  
#include <stdint.h> // For __u32, __u64  
#include <rxe_debug.h>

// 打印 rxe_send_wqe 结构体的函数  
void print_rxe_send_wqe(const struct rxe_send_wqe *wqe) {  
    printf("wqe addr: %p\n", (void*)&wqe);
    printf("rxe_send_wqe:\n");  
    printf("  wr: ");  
    print_rxe_send_wr(&wqe->wr); // 调用嵌套结构体的打印函数  
    printf("\n  av: ");  
    print_rxe_av(&wqe->av); // 调用嵌套结构体的打印函数  
    printf("\n  status: %u\n", wqe->status);  
    printf("  state: %u\n", wqe->state);  
    printf("  iova: %llu\n", (unsigned long long)wqe->iova);  
    printf("  mask: %s\n", rxe_wr_mask_to_str(wqe->mask));  
    printf("  first_psn: %u\n", wqe->first_psn);  
    printf("  last_psn: %u\n", wqe->last_psn);  
    printf("  ack_length: %u\n", wqe->ack_length);  
    printf("  ssn: %u\n", wqe->ssn);  
    printf("  has_rd_atomic: %u\n", wqe->has_rd_atomic);  
    printf("  dma: ");  
    print_rxe_dma_info(&wqe->dma); // 调用嵌套结构体的打印函数  
    printf("\n");  
}  

// 辅助函数，用于将枚举值映射到字符串  
const char* rxe_wr_mask_to_str(enum rxe_wr_mask mask) {  
    switch (mask) {  
        case WR_INLINE_MASK:  
            return "WR_INLINE_MASK";  
        case WR_ATOMIC_MASK:  
            return "WR_ATOMIC_MASK";  
        case WR_SEND_MASK:  
            return "WR_SEND_MASK";  
        case WR_READ_MASK:  
            return "WR_READ_MASK";  
        case WR_WRITE_MASK:  
            return "WR_WRITE_MASK";  
        case WR_LOCAL_MASK:  
            return "WR_LOCAL_MASK";  
        case WR_REG_MASK:  
            return "WR_REG_MASK";  
        default:  
            return "Unknown Mask";  
    }  
} 
  
// 示例的嵌套结构体打印函数（你需要根据实际的字段来编写）  
void print_rxe_send_wr(const struct rxe_send_wr *wr) {  
    // 假设 wr 有一些简单的字段  
    printf("(示例字段) wr_id: %u\n", wr->wr_id); // 假设 wr_id 是 wr 的一个字段  
}  
  
void print_rxe_av(const struct rxe_av *av) {  
    // 假设 av 有一些简单的字段  
    printf("(示例字段) path_mtu: %u\n", av->path_mtu); // 假设 path_mtu 是 av 的一个字段  
}  
  
void print_rxe_dma_info(const struct rxe_dma_info *dma) {  
    // 假设 dma 有一些简单的字段  
    printf("(示例字段) length: %u, address: %p\n", dma->length, (void *)dma->address); // 假设 length 和 address 是 dma 的字段  
}  

void print_rxe_pkt_info(const struct rxe_pkt_info *pkt) {  
    printf("pkt addr: %p\n", (void*)&pkt); 
    printf("qp addr: %p\n", (void*)&pkt->qp); 
    printf("wqe addr: %p\n", (void*)&pkt->wqe);  
    printf("mask: %s\n", rxe_wr_mask_to_str(wqe->mask)); 
    printf("psn: %u\n", pkt->psn);  
    printf("pkey_index: %u\n", pkt->pkey_index);  
    printf("paylen: %u\n", pkt->paylen);  
    printf("port_num: %u\n", pkt->port_num);  
    printf("opcode: %u\n", pkt->opcode);  
    printf("offset: %u\n", pkt->offset);  
} 