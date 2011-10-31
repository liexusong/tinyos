#include <syscall.h>
#include <types.h>

u32 usyscall(int num, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
	u32 ret;
	asm volatile (
		"int %1;"
		: "=a" (ret)
		: "i" (INTNO_SYSCALL),
		  "a" (num),
		  "b"(a1),
		  "c"(a2),
		  "d"(a3),
		  "D"(a4),
		  "S"(a5)
		: "cc", "memory");
	return ret;
}

int usys_puts(char *str)
{
	return usyscall(SYS_puts, (u32)str, 0, 0, 0, 0);
}

int usys_open(char *path, unsigned int flags)
{
	return usyscall(SYS_open, (u32)path, (u32)flags, 0, 0, 0);
}

int usys_close(int fd)
{
	return usyscall(SYS_close, (u32)fd, 0, 0, 0, 0);
}

int usys_fsync(int fd)
{
	return usyscall(SYS_fsync, (u32)fd, 0, 0, 0, 0);
}

int usys_read(int fd, char *buf, size_t size)
{
	return usyscall(SYS_read, (u32)fd, (u32)buf, (u32)size, 0, 0);
}

int usys_write(int fd, char *buf, size_t size)
{
	return usyscall(SYS_write, (u32)fd, (u32)buf, (u32)size, 0, 0);
}

off_t usys_lseek(int fd, off_t offset, unsigned int set)
{
	return usyscall(SYS_lseek, (u32)fd, (u32)offset, (u32)set, 0, 0);
}

int usys_fork(void)
{
	return usyscall(SYS_fork, 0, 0, 0, 0, 0);
}

void usys_yield(void)
{
	usyscall(SYS_yield, 0, 0, 0, 0, 0);
}

int usys_getpid(void)
{
	return usyscall(SYS_getpid, 0, 0, 0, 0, 0);
}

void usys_exit(int status)
{
	usyscall(SYS_exit, (u32)status, 0, 0, 0, 0);
}

int usys_wait(int *status)
{
	return usyscall(SYS_wait, (u32)status, 0, 0, 0, 0);
}

int usys_execute(char *path, int argc, char **argv)
{
	return usyscall(SYS_execute, (u32)path, (u32)argc, (u32)argv, 0, 0);
}

