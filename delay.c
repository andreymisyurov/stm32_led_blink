void delay(int ms) {
    // friquency 1MGz, delay 1000ms ~ 0.9s
    for (volatile int i = 0; i < ms; i++) {
            for (volatile int j = 0; j < ms; j++) { }
    }
}
