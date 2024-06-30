#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dispatch.h>
#include "common_02.h"

int main(int argc, char *argv[]){
    my_data_t msgReq, msgReply;
    int server_coid;

    if ((server_coid = name_open(ATTACH_POINT, 0)) == -1) {
        perror("name_open failed - server not found!");
        return EXIT_FAILURE;
    }
    printf("rtos-02-client started, server found\n");

    /* We would have pre-defined data to stuff here */
    msgReq.hdr.type = 0x00;
    msgReq.hdr.subtype = 0x00;

    /* Do whatever work you wanted with server connection */
    for (msgReq.data=0; msgReq.data < 5; msgReq.data++) {
        printf(" [press any key]\n"); getchar();
        printf("Client sending %d \n", msgReq.data);
        if (MsgSend(server_coid, &msgReq, sizeof(msgReq), &msgReply, sizeof(msgReply)) == -1) {
            perror("MsgSend Failed");
            break;
        }
        printf("... received reply: %d\n", msgReply.data);
    }
    /* Close the connection */
    name_close(server_coid);
    return EXIT_SUCCESS;
}