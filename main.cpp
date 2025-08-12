#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;

int vida_jogador = 100;
int vida_monstro = 100;
int turno_atual = 1;
int acuracia_jogador = 80; 
int acuracia_monstro = 70;
int velocidade_jogador = 15;
int velocidade_monstro = 10;

void mostrar_vida() {
    cout << endl << "[Vida Jogador: " << vida_jogador << "/100]" << endl;
    cout << "[Velocidade Jogador: " << velocidade_jogador << "]" << endl;

    cout << "[Vida Monstro: " << vida_monstro << "/100]" << endl;
    cout << "[Velocidade Monstro: " << velocidade_monstro << "]" << endl << endl;
}

void curar() {
    int cura = rand() % 21 + 10; 
    vida_jogador += cura;
    if(vida_jogador > 100) {
        vida_jogador = 100;
    }
    cout << "O Healer te curou em " << cura << " pontos!" << endl;
}

void debuffar() {
    static int ataque_inicial = 15;
    int novo_ataque = ataque_inicial * 0.85;
    cout << "O Debuffer enfraqueceu o monstro!" << endl;
    cout << "Dano do monstro reduziu de " << ataque_inicial << " para " << novo_ataque << endl;
    ataque_inicial = novo_ataque;
}

void reduzir_acuracia_jogador() {
    int reducao = 10; 
    if (acuracia_jogador > reducao) {
        acuracia_jogador -= reducao;
        cout << "O monstro lançou areia no seu OLHO! Sua acurácia caiu para " << acuracia_jogador << "%" << endl;
    } else {
        cout << "O monstro tentou reduzir sua acurácia, mas ela já está muito baixa!" << endl;
    }
}

void ataque_monstro() {
    if ((rand() % 100) < acuracia_monstro) {
        int dano = 15;
        vida_jogador -= dano;
        cout << "O monstro te deu " << dano << " de dano!" << endl;
    } else {
        cout << "O monstro errou o ataque!" << endl;
    }

   
    if ((rand() % 100) < 30) {
        reduzir_acuracia_jogador();
    }
}

void ataque_jogador() {
    if ((rand() % 100) < acuracia_jogador) {
        int dano = rand() % 25 + 1;
        vida_monstro -= dano;
        cout << "Voce deu " << dano << " de dano no monstro!" << endl;
    } else {
        cout << "Voce errou o ataque!" << endl;
    }
}

int main() {
	srand(time(0));
    
    cout << "===== BATALHA COMBATE RPG =====" << endl;
    cout << "Prepare-se para lutar!" << endl << endl;
    
    while(vida_jogador > 0 && vida_monstro > 0) {
        cout << endl << "----- TURNO " << turno_atual << " -----" << endl;
        
        velocidade_jogador = rand() % 16 + 5; 
        velocidade_monstro = rand() % 16 + 5; 
       
        if(velocidade_jogador >= velocidade_monstro) {
            ataque_jogador();
            if(vida_monstro <= 0) {
                cout << endl << "Voce venceu!(Não fez mais q sua obrigação, tem um healer e um debuffer do lado)" << endl;
                break;
            }

            ataque_monstro();
            if(vida_jogador <= 0) {
                cout << endl << "Voce foi derrotado! (Você é muito NEWBA KKKKKKKKKKKKKKKKKKK)" << endl;
                break;
            }
        } else {
            ataque_monstro();
            if(vida_jogador <= 0) {
                cout << endl << "Voce foi derrotado! (Você é muito NEWBA KKKKKKKKKKKKKKKKKKK)" << endl;
                break;
            }

            ataque_jogador();
            if(vida_monstro <= 0) {
                cout << endl << "Voce venceu!(Não fez mais q sua obrigação, tem um healer e um debuffer do lado)" << endl;
                break;
            }
        }

        curar();
        debuffar();
        mostrar_vida();
        
        turno_atual++;
    }
    
    cout << endl << "===== FIM DA BATALHA =====" << endl;
    cout << "Total de turnos: " << turno_atual - 1 << endl;
    
    return 0;
}
