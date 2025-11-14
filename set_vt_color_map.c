#include <fcntl.h>
#include <linux/vt.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <assert.h>
#include <limits.h>
#include <poll.h>

#include <stdint.h>
#include <stdio.h>

#include <linux/kd.h>

int main(void) {
    int fd = open("/dev/tty0", O_RDWR);
    assert(fd);
    uint8_t cmap[] = {
        0xff, 0xff, 0xff,
        0xaa, 0x00, 0x00,
        0x00, 0xaa, 0x00,
        0xaa, 0xaa, 0x00,
        0x00, 0x00, 0xaa,
        0xaa, 0x00, 0xaa,
        0x00, 0xaa, 0xaa,
        0x00, 0x00, 0x00,
        0xaa, 0xaa, 0xaa,
        0xff, 0x00, 0x00,
        0x00, 0xff, 0x00,
        0xff, 0xff, 0x00,
        0x00, 0x00, 0xff,
        0xff, 0x00, 0xff,
        0x00, 0xff, 0xff,
        0x55, 0x55, 0x55,
    };
    int ret = ioctl(fd, PIO_CMAP, cmap);
    if (ret != 0) {
        printf("GIO_CMAP ret: %d\n", ret);
    }
    ret = ioctl(fd, PIO_CMAP, cmap);
    if (ret != 0) {
        printf("PIO_CMAP ret: %d\n", ret);
    }
    close(fd);
    return 0;
}
