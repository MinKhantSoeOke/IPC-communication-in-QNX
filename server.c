#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dispatch.h>
#include "common_02.h"

/*** Server Side of the code ***/
int main() {
   name_attach_t *attach;
   my_data_t msg;
   int rcvid;

   /* Create a local name (/dev/name/local/...) */
   if ((attach = name_attach(NULL, ATTACH_POINT, 0)) == NULL) {
       return EXIT_FAILURE;
   }

   printf("rtos-02-server is running.\n");

   /* Do your MsgReceive's here now with the chid */
   while (1) {
       rcvid = MsgReceive(attach->chid, &msg, sizeof(msg), NULL);

       if (rcvid == -1) {/* Error condition, exit */
           break;
       }

       if (rcvid == 0) {/* Pulse received */
           printf("Received a pulse\n");
           continue;
       }

       /* A message (presumable ours) received, handle */
       printf("Server receive %d \n", msg.data);
       msg.data = msg.data + 1;
       printf(" [press any key]\n"); getchar();
       MsgReply(rcvid, EOK, &msg, sizeof(my_data_t));

   }

}