#include "../config.h"
#include "pin.H"

#include "branch_pred.h"
#include "libdft_api.h"
#include "libdft_core.h"
#include "syscall_desc.h"
#include "tagmap.h"
#include "tag_set.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include "string.h"

void sendData(void *data, int size);
void SocketInit();

void OutInit();
void OutFini();
void OutWrite(void *data, int size);

//void combineTag(std::vector<tag_seg> &tag_all, ADDRINT addr, u32 size);
// void MemRead(ADDRINT addr, uint32_t size);