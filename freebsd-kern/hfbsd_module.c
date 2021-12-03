/*************************************************
:: Hello, FreeBSD Kernel!
--------------------------------------------------
:: created by brianc2788@gmail.com
:: while following "Designing BSD Rootkits"
:: by J. Kong.
*************************************************/
#include <sys/param.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/systm.h>

// load & unload functions.
static int load(struct module *module, int cmd, void *arg){
    int error = 0;
    switch(cmd){
    case MOD_LOAD:
        uprintf("Hello, FreeBSD!\n",
                "KLD (Dynamic Kernel Linker) Module\n",
                "Authored by brianc2788@gmail.com\n");
        break;

    case MOD_UNLOAD:
         uprintf("Good-bye, Cruel FreeBSD!\n");
         break;

    default:
        error = EOPNOTSUPP;
        break;
    }

    return(error);
}

// 2nd DECLARE_MODULE arg:
static moduledata_t hfbsd_mod = {
    "hfbsd", /* module name */
    load,    /* module's event handler */
    NULL     /* book says extra?? maybe flags?? */
};

DECLARE_MODULE(hfbsd, hfbsd_mod, SI_SUB_DRIVERS, SI_ORDER_MIDDLE);
