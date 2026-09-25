#include <stdio.h> // en-têtes(headers)

union coords_gps {
    float valeurs[2];
    struct {
        float latitude, longitude;
    };
};

int main() {
    union coords_gps positions;
    
    printf("gps -trace %zu\n", sizeof(positions));
    positions.valeurs[0] = 48.85;
    positions.valeurs[1] = 2.35;

    printf("latitude: %f, longitude: %f\n", positions.latitude, positions.longitude);

    union coords_gps trace_positions[10] = {0};
    trace_positions[0].valeurs[0] = 65.85;
    trace_positions[1].valeurs[1] = 76.35;

    printf("trace[0] : latitude: %f, longitude: %f\n", trace_positions[0].latitude, trace_positions[0].longitude);

    return 0;
};
