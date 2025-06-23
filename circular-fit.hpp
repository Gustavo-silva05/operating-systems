#include <iostream>
#include <vector>
using namespace std;
class CircularFit {
private:
    vector<int> memory;
    int pointer = 0;

public:
    CircularFit(int size) {
        memory = vector<int>(size, 0);
    }

    void addMemory(int id, int size) {
        int memSize = memory.size();
        int start = -1;
        int count = 0;
        int scanned = 0;

        int i = pointer;

        while (scanned < memSize) {
            if (memory[i] == 0) {
                if (count == 0) start = i;
                count++;
                if (count == size) {
                    for (int j = start; j < start + size; j++) {
                        memory[j % memSize] = id;
                    }
                    pointer = (start + size) % memSize;
                    cout << "Processo " << id << " alocado a partir da posicao " << start << endl;
                    return;
                }
            } else {
                count = 0;
                start = -1;
            }
            i = (i + 1) % memSize;
            scanned++;
        }

        cout << "Não há espaço suficiente para o processo " << id << endl;
    }
    void removeMemory(int id) {

        for (int i = 0; i < memory.size(); i++) {
            if (memory[i] == id) {
                memory[i] = 0;
            }
        }

    }
    void printMemory() {
        for (int i = 0; i < memory.size(); i++) {
            cout << memory[i] << " ";
        }
        cout << endl;
    }
};