#include "../lib/maze_algo.h"
#include "../lib/int_handlers.h"

char process_point(){
    // Serial.printf("Processing point\n");
    Serial.printf("%d %d %d\t",lreading,center_reading,rreading);
    if(lreading > 1100){
        return 'w';
    }
    if(center_reading > 150){
        return 'n';
    }
    return 'e';
}