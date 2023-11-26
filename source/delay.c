static int divide(int dividend, int divisor) {
    int quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        quotient++;
    }
    return quotient;
}

void delay(int ms) {
    // friquency 1MGz, delay 1000ms ~1s
    ms += divide(ms,10);
    for (volatile int i = 0; i < ms; i++) {
            for (volatile int j = 0; j < ms; j++) { }
    }
}
