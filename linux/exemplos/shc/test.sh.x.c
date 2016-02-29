#if 0
	shc Version 3.8.7, Generic Script Compiler
	Copyright (c) 1994-2009 Francisco Rosales <frosal@fi.upm.es>

	shc -f test.sh 
#endif

static  char data [] = 
#define      chk1_z	22
#define      chk1	((&data[3]))
	"\337\042\131\150\064\025\205\322\214\376\041\340\234\036\047\157"
	"\222\134\140\337\235\304\250\352\252\130\024\353\126\123"
#define      xecc_z	15
#define      xecc	((&data[31]))
	"\232\256\234\000\034\261\111\056\323\112\334\337\326\206\044\232"
#define      opts_z	1
#define      opts	((&data[46]))
	"\010"
#define      rlax_z	1
#define      rlax	((&data[47]))
	"\014"
#define      msg1_z	42
#define      msg1	((&data[49]))
	"\051\130\332\116\367\117\372\027\011\012\066\255\240\154\027\045"
	"\000\211\214\223\250\206\223\076\115\214\231\066\257\337\214\144"
	"\025\262\354\243\142\006\337\157\204\233\132\334"
#define      tst2_z	19
#define      tst2	((&data[94]))
	"\216\203\334\261\274\330\004\336\134\112\357\104\305\020\157\304"
	"\110\227\064\105\271\005\067"
#define      lsto_z	1
#define      lsto	((&data[115]))
	"\123"
#define      text_z	137
#define      text	((&data[124]))
	"\236\224\303\365\342\305\217\255\327\163\267\265\113\277\122\216"
	"\015\010\134\364\024\025\325\124\110\145\226\352\002\251\244\354"
	"\006\261\252\345\027\035\175\205\070\321\305\047\344\037\360\144"
	"\072\005\160\252\312\314\022\036\370\134\264\053\037\202\247\366"
	"\175\317\147\026\260\247\032\106\226\256\160\154\260\273\326\051"
	"\144\123\123\074\252\357\067\202\123\064\203\157\142\000\255\331"
	"\341\164\305\162\257\171\060\110\074\371\362\116\164\177\000\012"
	"\277\320\213\062\236\130\220\342\312\273\146\202\270\031\276\201"
	"\330\310\140\163\276\310\274\241\335\151\266\245\214\327\121\022"
	"\362\157\176\150\155\215\211\223\265\262\157\241\074\353\057\277"
#define      chk2_z	19
#define      chk2	((&data[278]))
	"\326\302\245\022\210\206\147\205\334\263\332\023\347\166\227\066"
	"\257\074\161\046\113"
#define      pswd_z	256
#define      pswd	((&data[302]))
	"\153\251\365\141\213\215\023\220\062\140\150\355\115\007\207\017"
	"\007\057\130\350\052\120\167\355\023\311\377\146\234\303\123\357"
	"\273\011\234\333\226\260\153\311\021\324\266\136\333\076\156\343"
	"\156\306\313\230\027\103\206\053\015\206\221\251\111\345\230\005"
	"\356\065\340\205\345\113\116\367\037\005\126\373\103\304\336\262"
	"\213\252\113\243\356\321\316\373\130\137\245\242\105\075\247\064"
	"\162\207\271\130\323\007\117\363\015\245\356\121\152\315\003\366"
	"\170\116\231\147\040\147\143\170\307\010\033\015\105\302\101\270"
	"\112\372\020\035\002\140\020\017\006\377\140\160\315\144\146\105"
	"\262\000\255\323\147\020\114\057\031\147\074\137\052\176\027\164"
	"\171\050\221\173\210\242\213\216\241\354\376\157\120\145\265\002"
	"\145\142\325\315\163\042\375\215\211\071\354\263\270\003\047\061"
	"\054\271\255\264\134\070\103\376\044\102\155\164\247\042\167\015"
	"\205\115\332\370\157\327\206\370\021\162\254\311\166\324\373\242"
	"\216\250\127\352\340\232\350\005\334\126\172\203\170\361\221\376"
	"\077\153\367\256\103\175\247\125\357\123\037\146\050\032\010\266"
	"\302\137\240\243\371\272\360\070\052\157\240\227\374\052\052\262"
	"\334"
#define      msg2_z	19
#define      msg2	((&data[571]))
	"\205\010\035\322\373\022\125\355\061\023\007\027\215\277\255\007"
	"\112\102\354\321"
#define      tst1_z	22
#define      tst1	((&data[595]))
	"\353\362\115\255\277\337\222\362\100\034\316\327\114\206\345\362"
	"\100\006\215\127\040\073\172\201\001\043\123\142\337"
#define      date_z	1
#define      date	((&data[619]))
	"\045"
#define      shll_z	10
#define      shll	((&data[621]))
	"\175\117\101\135\333\144\214\316\003\070\013\317"
#define      inlo_z	3
#define      inlo	((&data[632]))
	"\072\030\331"/* End of data[] */;
#define      hide_z	4096
#define DEBUGEXEC	0	/* Define as 1 to debug execvp calls */
#define TRACEABLE	0	/* Define as 1 to enable ptrace the executable */

/* rtc.c */

#include <sys/stat.h>
#include <sys/types.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* 'Alleged RC4' */

static unsigned char stte[256], indx, jndx, kndx;

/*
 * Reset arc4 stte. 
 */
void stte_0(void)
{
	indx = jndx = kndx = 0;
	do {
		stte[indx] = indx;
	} while (++indx);
}

/*
 * Set key. Can be used more than once. 
 */
void key(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		do {
			tmp = stte[indx];
			kndx += tmp;
			kndx += ptr[(int)indx % len];
			stte[indx] = stte[kndx];
			stte[kndx] = tmp;
		} while (++indx);
		ptr += 256;
		len -= 256;
	}
}

/*
 * Crypt data. 
 */
void arc4(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		indx++;
		tmp = stte[indx];
		jndx += tmp;
		stte[indx] = stte[jndx];
		stte[jndx] = tmp;
		tmp += stte[indx];
		*ptr ^= stte[tmp];
		ptr++;
		len--;
	}
}

/* End of ARC4 */

/*
 * Key with file invariants. 
 */
int key_with_file(char * file)
{
	struct stat statf[1];
	struct stat control[1];

	if (stat(file, statf) < 0)
		return -1;

	/* Turn on stable fields */
	memset(control, 0, sizeof(control));
	control->st_ino = statf->st_ino;
	control->st_dev = statf->st_dev;
	control->st_rdev = statf->st_rdev;
	control->st_uid = statf->st_uid;
	control->st_gid = statf->st_gid;
	control->st_size = statf->st_size;
	control->st_mtime = statf->st_mtime;
	control->st_ctime = statf->st_ctime;
	key(control, sizeof(control));
	return 0;
}

#if DEBUGEXEC
void debugexec(char * sh11, int argc, char ** argv)
{
	int i;
	fprintf(stderr, "shll=%s\n", sh11 ? sh11 : "<null>");
	fprintf(stderr, "argc=%d\n", argc);
	if (!argv) {
		fprintf(stderr, "argv=<null>\n");
	} else { 
		for (i = 0; i <= argc ; i++)
			fprintf(stderr, "argv[%d]=%.60s\n", i, argv[i] ? argv[i] : "<null>");
	}
}
#endif /* DEBUGEXEC */

void rmarg(char ** argv, char * arg)
{
	for (; argv && *argv && *argv != arg; argv++);
	for (; argv && *argv; argv++)
		*argv = argv[1];
}

int chkenv(int argc)
{
	char buff[512];
	unsigned long mask, m;
	int l, a, c;
	char * string;
	extern char ** environ;

	mask  = (unsigned long)&chkenv;
	mask ^= (unsigned long)getpid() * ~mask;
	sprintf(buff, "x%lx", mask);
	string = getenv(buff);
#if DEBUGEXEC
	fprintf(stderr, "getenv(%s)=%s\n", buff, string ? string : "<null>");
#endif
	l = strlen(buff);
	if (!string) {
		/* 1st */
		sprintf(&buff[l], "=%lu %d", mask, argc);
		putenv(strdup(buff));
		return 0;
	}
	c = sscanf(string, "%lu %d%c", &m, &a, buff);
	if (c == 2 && m == mask) {
		/* 3rd */
		rmarg(environ, &string[-l - 1]);
		return 1 + (argc - a);
	}
	return -1;
}

#if !defined(TRACEABLE)

#define _LINUX_SOURCE_COMPAT
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#if !defined(PTRACE_ATTACH) && defined(PT_ATTACH)
#	define PTRACE_ATTACH	PT_ATTACH
#endif
void untraceable(char * argv0)
{
	char proc[80];
	int pid, mine;

	switch(pid = fork()) {
	case  0:
		pid = getppid();
		/* For problematic SunOS ptrace */
#if defined(__FreeBSD__)
		sprintf(proc, "/proc/%d/mem", (int)pid);
#else
		sprintf(proc, "/proc/%d/as",  (int)pid);
#endif
		close(0);
		mine = !open(proc, O_RDWR|O_EXCL);
		if (!mine && errno != EBUSY)
			mine = !ptrace(PTRACE_ATTACH, pid, 0, 0);
		if (mine) {
			kill(pid, SIGCONT);
		} else {
			perror(argv0);
			kill(pid, SIGKILL);
		}
		_exit(mine);
	case -1:
		break;
	default:
		if (pid == waitpid(pid, 0, 0))
			return;
	}
	perror(argv0);
	_exit(1);
}
#endif /* !defined(TRACEABLE) */

char * xsh(int argc, char ** argv)
{
	char * scrpt;
	int ret, i, j;
	char ** varg;

	stte_0();
	 key(pswd, pswd_z);
	arc4(msg1, msg1_z);
	arc4(date, date_z);
	if (date[0] && (atoll(date)<time(NULL)))
		return msg1;
	arc4(shll, shll_z);
	arc4(inlo, inlo_z);
	arc4(xecc, xecc_z);
	arc4(lsto, lsto_z);
	arc4(tst1, tst1_z);
	 key(tst1, tst1_z);
	arc4(chk1, chk1_z);
	if ((chk1_z != tst1_z) || memcmp(tst1, chk1, tst1_z))
		return tst1;
	ret = chkenv(argc);
	arc4(msg2, msg2_z);
	if (ret < 0)
		return msg2;
	varg = (char **)calloc(argc + 10, sizeof(char *));
	if (!varg)
		return 0;
	if (ret) {
		arc4(rlax, rlax_z);
		if (!rlax[0] && key_with_file(shll))
			return shll;
		arc4(opts, opts_z);
		arc4(text, text_z);
		arc4(tst2, tst2_z);
		 key(tst2, tst2_z);
		arc4(chk2, chk2_z);
		if ((chk2_z != tst2_z) || memcmp(tst2, chk2, tst2_z))
			return tst2;
		if (text_z < hide_z) {
			/* Prepend spaces til a hide_z script size. */
			scrpt = malloc(hide_z);
			if (!scrpt)
				return 0;
			memset(scrpt, (int) ' ', hide_z);
			memcpy(&scrpt[hide_z - text_z], text, text_z);
		} else {
			scrpt = text;	/* Script text */
		}
	} else {			/* Reexecute */
		if (*xecc) {
			scrpt = malloc(512);
			if (!scrpt)
				return 0;
			sprintf(scrpt, xecc, argv[0]);
		} else {
			scrpt = argv[0];
		}
	}
	j = 0;
	varg[j++] = argv[0];		/* My own name at execution */
	if (ret && *opts)
		varg[j++] = opts;	/* Options on 1st line of code */
	if (*inlo)
		varg[j++] = inlo;	/* Option introducing inline code */
	varg[j++] = scrpt;		/* The script itself */
	if (*lsto)
		varg[j++] = lsto;	/* Option meaning last option */
	i = (ret > 1) ? ret : 0;	/* Args numbering correction */
	while (i < argc)
		varg[j++] = argv[i++];	/* Main run-time arguments */
	varg[j] = 0;			/* NULL terminated array */
#if DEBUGEXEC
	debugexec(shll, j, varg);
#endif
	execvp(shll, varg);
	return shll;
}

int main(int argc, char ** argv)
{
#if DEBUGEXEC
	debugexec("main", argc, argv);
#endif
#if !defined(TRACEABLE)
	untraceable(argv[0]);
#endif
	argv[1] = xsh(argc, argv);
	fprintf(stderr, "%s%s%s: %s\n", argv[0],
		errno ? ": " : "",
		errno ? strerror(errno) : "",
		argv[1] ? argv[1] : "<null>"
	);
	return 1;
}
