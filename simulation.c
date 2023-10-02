#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

struct diner {
    int arrival_time;
    int num_burgers;
    int num_fries;
    int coke;
    sem_t diner_mutex
};


struct data {
    int num_diners;
    int num_tables;
    int num_cooks;
    struct diner **diners;
};

struct data* readFile(char *filename){
    FILE *f = fopen(filename, "r");
    struct data *simdata = (struct data *)malloc(sizeof(struct data)); 
    fscanf (f, "%d", &(simdata->num_diners));
    fscanf (f, "%d", &(simdata->num_tables));
    fscanf (f, "%d", &(simdata->num_cooks));
    simdata->diners = (struct diner **)malloc(sizeof(struct diner*) * (simdata->num_diners));
    for (int i=0; i<simdata->num_diners;i++){
        struct diner *d = (struct diner *)malloc(sizeof(struct diner));
        fscanf (f, "%d,%d,%d,%d", &(d->arrival_time),&(d->num_burgers),&(d->num_fries),&(d->coke));
        simdata->diners[i]=d;
    }
    fclose(f);
    return simdata;
}

void *diner_t(struct diner* diner_data){
    while (time(NULL)-(diner_data->start_time) > diner_data->arrival_time){

    }
    sem_wait(diner_data->tables);
    
    


    sem_post(diner_data->tables);
}

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Please pass input file name as argument");
        return 0;
    }
    time_t start_time;
    start_time = time(NULL);
    struct data *simdata = readFile(argv[1]);
    pthread_t thread_id;
    
    for (int i = 0; i < simdata->num_diners; i++){
        
        /*add whatever is necessary to diner_data
        time
        semaphore
        */
        pthread_create(thread_id, NULL, diner_t, &diner_data);
    }
    
    return 0;

}