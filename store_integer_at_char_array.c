/* This method gets integer from stored char array 
 * usage: to_int(char_ar[stored_point], &result) 
 */
int to_int(char* ar, int* number){
    int a,b,c,d;
    a = ((int)ar[0]) & 0x000000ff;
    b = (((int)ar[1]) << 8) & 0x0000ff00 ;
    c = (((int)ar[2]) << 16) & 0x00ff0000;
    d = (((int)ar[3]) << 24) & 0xff000000;
    *number = (a|b|c|d);
    return 1;
}

/* This method puts integer to char array with splitting it to bytes 
 * usage: to_int(char_ar, number, where_to_put) 
 */
int to_char(char* ar, int number, int point){
    if(point < 0) {
        return 0;
    }
    ar[point] = (char)(number & 0x000000ff);
    ar[point + 1] = (char)((number & 0x0000ff00) >> 8);
    ar[point + 2] = (char)((number & 0x00ff0000) >> 16);
    ar[point + 3] = (char)((number & 0xff000000) >> 24);
    return 1; 
}
