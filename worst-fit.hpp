#include <iostream>
#include <vector>

using namespace std;

class WorstFit {
private:
    vector<int> memory;

public:
    WorstFit(int size) {
        memory = vector<int>(size, 0);
    }

    void addMemory(int id, int size) {
        int maxBlockStart = -1;
        int maxBlockSize = 0;

        int i = 0;
        while (i < memory.size()) {
            if (memory[i] == 0) {
                int start = i;
                int length = 0;

                while (i < memory.size() && memory[i] == 0) {
                    length++;
                    i++;
                }

                if (length >= size && length > maxBlockSize) {
                    maxBlockSize = length;
                    maxBlockStart = start;
                }
            } else {
                i++;
            }
        }

        if (maxBlockStart == -1) {
            cout << "Não há espaço suficiente para o processo " << id << endl;
        } else {
            for (int j = maxBlockStart; j < maxBlockStart + size; j++) {
                memory[j] = id;
            }
            cout << "Processo " << id << " alocado a partir da posicao " << maxBlockStart << endl;
        }
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
