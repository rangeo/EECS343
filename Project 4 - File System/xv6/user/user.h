#ifndef _USER_H_
#define _USER_H_

struct stat;

#ifndef _KEY_H_
#define _KEY_H_
struct Key {
  char key[10];  // at most 10 bytes for key
};
#endif // _KEY_H_

// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(char*, int);
int mknod(char*, short, short);
int unlink(char*);
int fstat(int fd, struct stat*);
int link(char*, char*);
int mkdir(char*);
int chdir(char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);
int tagFile(int fileDescriptor, char* key, char* value, int valueLength);
int removeFileTag(int fileDescriptor, char* key);
int getFileTag(int fileDescriptor, char* key, char* buffer, int length);
int getAllTags(int fileDescriptor, struct Key *keys, int maxTags);
int getFilesByTag(char* key, char* value, int valueLength, char* results, int resultsLength);

// user library functions (ulib.c)
int stat(char*, struct stat*);
char* strcpy(char*, char*);
void *memmove(void*, void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, char*, ...);
char* gets(char*, int max);
uint strlen(char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);

#endif // _USER_H_

