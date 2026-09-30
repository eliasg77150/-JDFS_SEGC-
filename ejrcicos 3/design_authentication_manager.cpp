#include <unordered_map>
#include <string>
using namespace std;

class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) : ttl(timeToLive) {}

    void generate(string tokenId, int currentTime) {
        expiracion[tokenId] = currentTime + ttl;
    }

    void renew(string tokenId, int currentTime) {
        auto it = expiracion.find(tokenId);
        if (it != expiracion.end() && it->second > currentTime) {
            it->second = currentTime + ttl;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int contador = 0;
        for (auto& [token, expira] : expiracion) {
            if (expira > currentTime) {
                ++contador;
            }
        }
        return contador;
    }

private:
    int ttl;
    unordered_map<string, int> expiracion; // tokenId -> tiempo de expiracion
};
