#include <iostream>
#include <vector>
#include <string>
using namespace std;


//criacao da classe Aluno
class Aluno {
public:
	//construtor
	Aluno(string nome, float media) :
		nome(nome), media(media) {
	}

	string nome;
	float media;

	void verNaLista() {
		cout << "Nome: " << nome << " - Media: " << media << endl;
	}
};

//Criacao do vector para armazenar os objetos dos alunos
vector<Aluno> listaAlunos;

//criacao das funcoes
void adicionar() {

	string nome;
	int numNotas;
	float media;

	// Pegar do utilizador os atributos dos alunos
	cout << "Nome: ";
	getline(cin, nome);

	cout << "Quantas notas deseja adicionar? ";
	cin >> numNotas;

	// Calcular a media das notas
	float soma = 0;
	for (int i = 1; i <= numNotas; i++) {
		float nota;
		cout << "Nota: ";
		cin >> nota;
		soma += nota;
	}
	media = soma / numNotas;

	// Adicionar o nome e media do aluno a lista

	listaAlunos.emplace_back(nome, media);

	cout << "Media do aluno: " << media << endl;
	cout << "\n";
	cout << "Aluno adicionado a lista" << endl;
	cout << "\n";
}
void listar() {
	cout << "\n";
	cout << "Lista de alunos: " << endl;
	for (auto aluno : listaAlunos) {
		aluno.verNaLista();
	}
	cout << "\n";
}
void remover() {
	string nome;
	cout << "\n";
	cout << "Nome do aluno que deseja remover: ";
	getline(cin, nome);

	auto it = listaAlunos.begin();
	while (it != listaAlunos.end()) {
		if (it->nome == nome) {
			listaAlunos.erase(it);
			cout << "\n";
			cout << "Aluno removido" << endl;
			cout << "\n";
			return;
		}
		else {
			++it;
		}
	}
	cout << "\n";
	cout << "Aluno nao encontrado" << endl;
	cout << "\n";
}
void editar() {
	string nome;
	cout << "Digite o nome do aluno que deseja editar: ";
	getline(cin, nome);

	auto it = listaAlunos.begin();
	while (it != listaAlunos.end()) {
		if (it->nome == nome) {

			int numNotas;
			cout << "\n";
			cout << "Quantas notas deseja por? ";
			cin >> numNotas;

			// Calcular a media das notas
			float soma = 0;
			for (int i = 1; i <= numNotas; i++) {
				float nota;
				cout << "Nota: ";
				cin >> nota;
				soma += nota;
			}
			it->media = soma / numNotas;
			cout << "\n";
			cout << "Nova media: " << it->media << endl;
			cout << "\n";
			return;
		}
		else {
			++it;
		}
	}
	cout << "\n";
	cout << "Aluno nao encontrado";
	cout << "\n";

}


int main() {
	while (true) {
		int escolha;
		cout << "Escolha uma das opcoes:" << endl;
		cout << "1: Adicionar um aluno" << endl;
		cout << "2: Remover um aluno" << endl;
		cout << "3: Editar as notas de um aluno" << endl;
		cout << "4: Mostrar lista de alunos" << endl;
		cout << "5: Encerrar o programa" << endl;
		cout << "Escolha a opcao(1, 2, 3, 4 ou 5): ";
		cin >> escolha;
		cout << "\n";
		cin.ignore();

		switch (escolha) {
		case 1:
			adicionar();
			break;
		case 2:
			remover();
			break;
		case 3:
			editar();
			break;
		case 4:
			listar();
			break;
		case 5:
			cout << "Programa encerrado.";
			return 0;
		default:
			cout << "\nOpcao invalida. Por favor, escolha 1, 2 ou 3.\n" << endl;
		}
	}
	return 0;
}