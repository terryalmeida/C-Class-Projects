#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//////////////////////
// data definitions //
//////////////////////

#define NAME_LEN 20
#define SIZE_LEN 3

struct job {
	char job_name[NAME_LEN+1], user_name[NAME_LEN+1];
	int num_cpus, num_gpus, memory, priority;
	double time;
	struct job *next;
};

/////////////////////////
// function prototypes //
/////////////////////////

void help();
void read(char *job_name, char *user_name, int *num_cpus, int *num_gpus, int *memory, double *time, int *priority);
struct job * add_job(struct job *scheduler, char *job_name, char *user_name, int num_cpus, int num_gpus, int memory, double time, int priority);
struct job * pop_job(struct job *scheduler);
void list_user(struct job *scheduler, char *user_name);
void list_jobs(struct job *scheduler, int num_cpus, int num_gpus, int memory, double time);
void list_all_jobs(struct job *scheduler);
struct job * clear_jobs(struct job *scheduler);

///////////////////
// main function //
///////////////////

int main() {
	char code;
	char job_name[NAME_LEN+1], user_name[NAME_LEN+1];
	int num_cpus, num_gpus, memory, priority;
	double time;

	struct job *scheduler = NULL;

	help();
	printf("\n");

	for (;;) {
		// read operation code
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n') /* skips to end of line */
			;

		// run operation
		switch (code) {
			case 'h':
				help();
				break;
			case 'a':
				read(job_name, user_name, &num_cpus, &num_gpus, &memory, &time, &priority);
				scheduler = add_job(scheduler, job_name, user_name, num_cpus, num_gpus, memory, time, priority);
				break;
			case 'p':
				scheduler = pop_job(scheduler);
				break;
			case 'u':
				read(NULL, user_name, NULL, NULL, NULL, NULL, NULL);
				list_user(scheduler, user_name);
				break;
			case 'j':
				read(NULL, NULL, &num_cpus, &num_gpus, &memory, &time, NULL);
				list_jobs(scheduler, num_cpus, num_gpus, memory, time);
				break;
			case 'l':
				list_all_jobs(scheduler);
				break;
			case 'q':
				scheduler = clear_jobs(scheduler);
				return 0;
			default:
				printf("Illegal operation code!\n");
		}
		printf("\n");
	}
}

//////////////////////////
// function definitions //
//////////////////////////

void help() {
	printf("List of operation codes:\n");
	printf("\t'h' for help;\n");
	printf("\t'a' for adding a job to the scheduler;\n");
	printf("\t'p' for removing a job from the scheduler;\n");
	printf("\t'u' for searching jobs per user;\n");
	printf("\t'j' for searching jobs per capacity;\n");
	printf("\t'l' for listing all jobs;\n");
	printf("\t'q' for quit.\n");
}

void read(char *job_name, char *user_name, int *num_cpus, int *num_gpus, int *memory, double *time, int *priority) {
	if(job_name != NULL) {
		printf("Enter the name of the job: ");
		scanf("%s", job_name);
	}
	if(user_name != NULL) {
		printf("Enter the name of the user: ");
		scanf("%s", user_name);
	}
	if(num_cpus != NULL) {
		printf("Enter the number of CPUs: ");
		scanf("%d", num_cpus);
	}
	if(num_gpus != NULL) {
		printf("Enter the number of GPUs: ");
		scanf("%d", num_gpus);
	}
	if(memory != NULL) {
		printf("Enter the amount of memory: ");
		scanf("%d", memory);
	}
	if(time != NULL) {
		printf("Enter the amount of time: ");
		scanf("%lf", time);
	}
	if(priority != NULL) {
		printf("Enter the priority: ");
		scanf("%d", priority);
	}
}

/////////////////////////////////////////////////////////
// WARNING - WARNING - WARNING - WARNING - WARNING     //
/////////////////////////////////////////////////////////
// Do not modify anything before this point, otherwise //
// your solution will be considered incorrect.         //
/////////////////////////////////////////////////////////

//Terry Almeida
//Modified on 4/7/2023
//This program manages a scheduler connected to a computer cluster.
//Through this program we are able to assign job names, user names, number of cpus, number of gpus, memory time and priority to each job.
//This scheduler allows jobs to be added, removed, jobs to be listed by user name, or hardware criteria, and the ability to list all jobs or clear jobs.

struct job * add_job(struct job *scheduler, char *job_name, char *user_name, int num_cpus, int num_gpus, int memory, double time, int priority) {

    //This allocates memory for a new job struct and assigns the new job pointer to its address
	struct job *new_job = (struct job *) malloc(sizeof(struct job));

    //copies the job name from the scheduler to the new job
	strcpy(new_job->job_name, job_name);

    //copies the user name
	strcpy(new_job->user_name, user_name);

	//copies the number of cpus, gpus, memory, time, and priority
	new_job->num_cpus = num_cpus;
	new_job->num_gpus = num_gpus;
	new_job->memory = memory;
	new_job->time = time;
	new_job->priority = priority;

    //makes the new job pointer to null, which is the last job in the linked list
	new_job->next = NULL;

    //sets new job to beginning if scheduler is empty
	if(scheduler == NULL)
        return new_job;

	//initialize current point cur to beginning of scheduler linked list
    struct job *cur = scheduler;

    //go through list until reaching null, the last job
    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    //set the next pointer to the last job to append new job to the end of the scheduler linked list
    cur->next = new_job;

    //return the head of the scheduler linked list
    return scheduler;
}

struct job * pop_job(struct job *scheduler) {
    //if the scheduler is not empty
	if (scheduler != NULL)
    {
        //print current job in scheduler
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
        printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
        printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", scheduler->job_name, scheduler->user_name,  scheduler->num_cpus, scheduler->num_gpus, scheduler->memory, scheduler->time, scheduler->priority);
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");

        //assign next job pointer to next job in the scheduler and free the previous scheduler pointer memory
        struct job *next_job = scheduler->next;
        free(scheduler);

        //return the next job pointer to the updated scheduler linked list
        return next_job;
    }
    //return NULL if list is empty
    return NULL;
}

void list_user(struct job *scheduler, char *user_name) {

    //header printed variable to only print header once
    int header_printed = 0;
	// if scheduler is not empty
    if (scheduler != NULL)
    {
        //initialize cur job point to top of scheduler linked list
        struct job *cur_job = scheduler;

        //while cur_job has not reached the end of the scheduler linked list
        while (cur_job != NULL)
        {


            //if current job user name string matches user name passed to this function, print jobs containing that user name
            if(strcmp(cur_job->user_name, user_name) == 0)
            {
                //only print once if not
                if(header_printed == 0)
                {
                    //print output table format
                    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
                    printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
                    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
                    header_printed = 1;
                }
                printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n",cur_job->job_name, cur_job->user_name, cur_job->num_cpus, cur_job->num_gpus, cur_job->memory, cur_job->time, cur_job->priority);
                printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
            }
            //set current job to the next job on the linked list
            cur_job = cur_job->next;
        }

    }
}

void list_jobs(struct job *scheduler, int num_cpus, int num_gpus, int memory, double time) {

    //declare header printed int variable to only print table header once
    int header_printed = 0;

    //if scheduler is not empty
    if (scheduler != NULL)
    {
        //initialize cur job point to top of scheduler linked list
        struct job *cur_job = scheduler;

        //while going through the list, if job matches the passed parameters (num cpus, num gpus, memory and time) then print job
        //and move cur job pointer to next job on linked list, also only print header once
        while (cur_job != NULL)
        {
            if (cur_job->num_cpus == num_cpus  && cur_job->num_gpus == num_gpus && cur_job->memory == memory && cur_job->time == time)
            {
                if(header_printed == 0)
                {
                    //print table format
                    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
                    printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
                    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
                    header_printed = 1;
                }
                printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", cur_job->job_name, cur_job->user_name, num_cpus, num_gpus, memory, time, cur_job->priority);
                printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
            }
            cur_job = cur_job->next;
        }
    }
}

void list_all_jobs(struct job *scheduler) {

    //if scheduler is not empty
    if (scheduler != NULL)
    {
        //initialize cur job point to top of scheduler linked list
        struct job *cur_job = scheduler;

        //print table format
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
        printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");

        //while going through linked list, print all jobs found that are not null, while moving the cur job pointer down the list
        while (cur_job != NULL)
        {
            printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n",cur_job->job_name, cur_job->user_name, cur_job->num_cpus, cur_job->num_gpus, cur_job->memory, cur_job->time, cur_job->priority);
            printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
            cur_job = cur_job->next;
        }
    }
}

struct job * clear_jobs(struct job *scheduler) {

    //initialize cur job point to top of scheduler linked list
    struct job *cur_job = scheduler;

    //while going through scheduler linked list, save the current job in the scheduler
    //update the current job to the next job and delete/free the saved job
	while (cur_job != NULL)
    {
        scheduler = cur_job;
        cur_job = cur_job->next;
        free(scheduler);
    }
    //return the cur_job position
    return cur_job;
}

