void delay(int ms) {
    ms *= 1.1;
    for (volatile int i = 0; i < ms; i++) {
            for (volatile int j = 0; j < ms; j++) { }
    }
}
