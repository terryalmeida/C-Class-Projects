job.o: job.c job.h
	gcc -c job.c

project10_scheduler.o: project10_scheduler.c job.h
	gcc -c project10_scheduler.c 

project10_scheduler: job.o project10_scheduler.o
	gcc job.o project10_scheduler.o -o project10_scheduler
clean:
	rm job.o project10_scheduler.o project10_scheduler
