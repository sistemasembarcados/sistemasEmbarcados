#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/inotify.h>
#include <unistd.h>

#define EVENT_SIZE  (sizeof(struct inotify_event))
#define BUF_LEN     (1024 * (EVENT_SIZE + 16))

// gcc inotify_example.c -o inotify_example

int main(void) {
	int length, i = 0;
	int fd;
	int wd;
	char buffer[BUF_LEN];
	const char *root = "/tmp";

	printf("monitorando o diretorio /tmp\n");
	
	sleep(1);
	
	fd = inotify_init();

	if (fd < 0) {
		perror("erro na chamada: inotify_init");
		exit(1);
    }

	wd = inotify_add_watch(fd, root, IN_MODIFY | IN_CREATE | IN_DELETE);
	length = read(fd, buffer, BUF_LEN);

	if (length < 0) {
		perror("erro ao ler o buffer");
		exit(1);
	}

	while (i < length) {
		struct inotify_event *event = (struct inotify_event *) &buffer[i];
		if (event->len) {
			if (event->mask & IN_CREATE) {
				printf("O arquivo %s foi criado.\n", event->name);
			} else if (event->mask & IN_DELETE) {
				printf("O arquivo %s foi deletado.\n", event->name);
			} else if (event->mask & IN_MODIFY) {
				printf("O arquivo %s foi modificado.\n", event->name);
			}
		}
		i += EVENT_SIZE + event->len;
	}

	inotify_rm_watch(fd, wd);
	close(fd);
	return 0;
} 
