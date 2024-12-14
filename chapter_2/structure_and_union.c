#include <stdio.h>
#include <string.h>
#

int main(void) {
    struct sigrecord {
        int signum;
        char signame[20];
        char sigdesc[100];
    };

    struct sigrecord sigline;
    // use structure like a type
    typedef struct sigrecord sigrecord;
    sigrecord *sigline_p;    // define variable

    sigline.signum = 5;
    strcpy(sigline.signame, "SIGINT");
    strcpy(sigline.sigdesc, "Interrupt from keyboard");

    sigline_p = &sigline;

    sigline_p->signum = sigline.signum * 5;

    printf("signum =  %d\n", sigline_p->signum);
    printf("signame =  %s\n", sigline_p->signame);
    printf("sigdesc =  %s\n", sigline_p->sigdesc);

    printf("\n\n\n\n");



    // union storage only one type
    // because memory is allocated to only one type element
    // It is using in embedded device for save memory
    union current_time {
        int time_i;
        double time_d;
        float time_f;
    };
    union current_time var_time, *var_time_p;

    var_time.time_i = 1111111;
    var_time_p = &var_time;

    printf(
            "time_i =  %d, time_d =  %f, time_f =  %f\n",
            var_time_p->time_i, var_time_p->time_d, var_time_p->time_f
    );

    var_time.time_f = 4.44444;

    printf(
            "time_i =  %d, time_d =  %f, time_f =  %f\n",
            var_time_p->time_i, var_time_p->time_d, var_time_p->time_f
    );

    var_time.time_d = 99.999999;

    printf(
            "time_i =  %d, time_d =  %f, time_f =  %f\n",
            var_time_p->time_i, var_time_p->time_d, var_time_p->time_f
    );

    printf("\n\n\n");



    // trick with union
    // How do you know which structure is filled at that time?
    // As we know, a union allocates memory only for one structure.
    // However, we can request any structure and any variables at any time.
    // The trick is that in all structures in the union,
    //      we add on the first place variable with a value of what type of structure filled at that moment.
    // For example:

    // type: 1 - i, 2 - d, 3 - f
    union number_time {
        struct {
            int type;
            int time;
        } i;
        struct {
            int type;
            double time;
        } d;
        struct {
            int type;
            float time;
        } f;
    };
    union number_time n_time, *n_time_p;

    n_time.i.type = 1;
    n_time.i.time = 111111;

    printf(
            "current structure type: i.type = %d, d.type = %d, f.type = %d\n"
            "time = %d\n",
           n_time.i.type, n_time.d.type, n_time.f.type,
           n_time.i.time
    );

    n_time.d.type = 2;
    n_time.d.time = 2.22222;

    printf(
            "current structure type: i.type = %d, d.type = %d, f.type = %d\n"
            "time = %f\n",
            n_time.i.type, n_time.d.type, n_time.f.type,
            n_time.d.time
    );

    n_time.f.type = 3;
    n_time.f.time = 3.3333;

    printf(
            "current structure type: i.type = %d, d.type = %d, f.type = %d\n"
            "time = %f\n",
            n_time.i.type, n_time.d.type, n_time.f.type,
            n_time.f.time
    );
}
