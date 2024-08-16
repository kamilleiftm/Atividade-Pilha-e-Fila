#include <stdio.h>

struct No {
    int valor;
    No* prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }
};

struct Fila {
    No* inicio;
    No* fim;
    int n;

    Fila() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void enfileirar(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void desenfileirar() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    int frente() {
        if (inicio == NULL) return 0;
        return inicio->valor;
    }

    bool estaVazia() {
        return inicio == NULL;
    }
};

struct Pilha {
    No* topo;
    int n;

    Pilha() {
        topo = NULL;
        n = 0;
    }

    void inserir(int valor) {
        No* novo = new No(valor);
        if (topo == NULL) {
            topo = novo;
        } else {
            novo->prox = topo;
            topo = novo;
        }
        n++;
    }

    void remover() {
        if (n == 0) return;
        if (n == 1) {
            delete(topo);
            topo = NULL;
            n = 0;
            return;
        }
        No* aux = topo;
        topo = topo->prox;
        delete(aux);
        n--;
    }

    int topoValor() {
        if (topo == NULL) return 0;
        return topo->valor;
    }

    bool estaVazia() {
        return topo == NULL;
    }
};

void inverterFila(Fila& fila) {
    Pilha pilha;

    // Transferir elementos da fila para a pilha
    while (!fila.estaVazia()) {
        pilha.inserir(fila.frente());
        fila.desenfileirar();
    }

    // Transferir elementos da pilha de volta para a fila
    while (!pilha.estaVazia()) {
        fila.enfileirar(pilha.topoValor());
        pilha.remover();
    }
}

int main() {
    Fila f;

    // Enfileirar elementos
    f.enfileirar(1);
    f.enfileirar(2);
    f.enfileirar(3);
    f.enfileirar(4);

    // Inverter a fila
    inverterFila(f);

    // Desenfileirar e exibir elementos invertidos
    while (!f.estaVazia()) {
        printf("%d ", f.frente());
        f.desenfileirar();
    }
    printf("\n");  // Nova linha no final da saída

    return 0;
}
