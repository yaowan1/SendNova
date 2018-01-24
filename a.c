/*************************************************************************
	> File Name: a.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Mon 11 Dec 2017 10:15:37 AM CST
 ************************************************************************/

#include <ev.h>
#include <stdio.h>

ev_io stdin_watcher;
ev_timer timeout_watcher;

static void stdin_cb(EV_P_ ev_io* w,int revents)
{
	puts("stdin ready");
	ev_io_stop(EV_A_ w);
	ev_break(EV_A_ EVBREAK_ALL);
}

static int val = 0;

static void timeout_cb(EV_P_ ev_timer* w,int revents)
{
	printf("%d\n",val++);
	//puts("timeout");
	//ev_break(EV_A_ EVBREAK_ONE);
}

int main()
{

	struct ev_loop* loop = EV_DEFAULT; 

	ev_io_init(&stdin_watcher,stdin_cb,0,EV_READ);
	ev_io_start(loop,&stdin_watcher);

	ev_timer_init(&timeout_watcher,timeout_cb,0,1);
	ev_timer_start(loop,&timeout_watcher);

	ev_run(loop,0);

	printf("end\n");
	return 0;
}
