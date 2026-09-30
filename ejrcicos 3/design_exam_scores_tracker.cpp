#include <vector>
#include <algorithm>
using namespace std;

class ExamTracker {
public:
    ExamTracker() {}

    void record(int time, int score) {
        tiempos.push_back(time);
        long long prefijoAnterior = sumaPrefijo.empty() ? 0LL : sumaPrefijo.back();
        sumaPrefijo.push_back(prefijoAnterior + score);
    }

    long long totalScore(int startTime, int endTime) {
        // Como record() siempre llega en orden estrictamente creciente de tiempo,
        // 'tiempos' ya esta ordenado y podemos usar busqueda binaria.
        int izq = lower_bound(tiempos.begin(), tiempos.end(), startTime) - tiempos.begin();
        int der = upper_bound(tiempos.begin(), tiempos.end(), endTime) - tiempos.begin() - 1;

        if (izq > der || tiempos.empty()) {
            return 0LL;
        }

        long long sumaHastaDer = sumaPrefijo[der];
        long long sumaAntesDeIzq = (izq > 0) ? sumaPrefijo[izq - 1] : 0LL;
        return sumaHastaDer - sumaAntesDeIzq;
    }

private:
    vector<int> tiempos;
    vector<long long> sumaPrefijo;
};
