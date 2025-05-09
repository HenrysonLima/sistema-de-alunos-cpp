#include <iostream>
#include <vector>
#include <string>

//criacao da classe Aluno
class Aluno {
public:
	//construtor
	Aluno(std::string nome, float media) :
		nome(nome), media(media) {
	}

	std::string nome;
	float media;

	void verNaLista() {
		std::cout << "Nome: " << nome << " - Media: " << media << std::endl;
	}
};

//Criacao do vector para armazenar os objetos dos alunos
std::vector<Aluno> listaAlunos;

//criacao das funcoes
void adicionar() {

	std::string nome;
	int numNotas;
	float media;

	// Pegar do utilizador os atributos dos alunos
	std::cout << "Nome: ";
	std::getline(std::cin, nome);

	std::cout << "Quantas notas deseja adicionar? ";
	std::cin >> numNotas;

	// Calcular a media das notas
	float soma = 0;
	for (int i = 1; i <= numNotas; i++) {
		float nota;
		std::cout << "Nota: ";
		std::cin >> nota;
		soma += nota;
	}
	media = soma / numNotas;

	// Adicionar o nome e media do aluno a lista

	listaAlunos.emplace_back(nome, media);

	std::cout << "Media do aluno: " << media << std::endl;
	std::cout << "\n";
	std::cout << "Aluno adicionado a lista" << std::endl;
	std::cout << "\n";
}
void listar() {
	std::cout << "\n";

	if (listaAlunos.size() == 0) {
		std::cout << "Nao existem alunos cadastrados\n\n";
	}
	else {
		std::cout << "Lista de alunos: " << std::endl;
		for (auto aluno : listaAlunos) {
			aluno.verNaLista();
		}
		std::cout << "\n";
	}
}
void remover() {
	std::string nome;
	std::cout << "\n";
	std::cout << "Nome do aluno que deseja remover: ";
	std::getline(std::cin, nome);

	auto it = listaAlunos.begin();
	while (it != listaAlunos.end()) {
		if (it->nome == nome) {
			listaAlunos.erase(it);
			std::cout << "\n";
			std::cout << "Aluno removido" << std::endl;
			std::cout << "\n";
			return;
		}
		else {
			++it;
		}
	}
	std::cout << "\n";
	std::cout << "Aluno nao encontrado" << std::endl;
	std::cout << "\n";
}
void editar() {
	std::string nome;
	std::cout << "Digite o nome do aluno que deseja editar: ";
	std::getline(std::cin, nome);

	auto it = listaAlunos.begin();
	while (it != listaAlunos.end()) {
		if (it->nome == nome) {

			int numNotas;
			std::cout << "\n";
			std::cout << "Quantas notas deseja por? ";
			std::cin >> numNotas;

			// Calcular a media das notas
			float soma = 0;
			for (int i = 1; i <= numNotas; i++) {
				float nota;
				std::cout << "Nota: ";
				std::cin >> nota;
				soma += nota;
			}
			it->media = soma / numNotas;
			std::cout << "\n";
			std::cout << "Nova media: " << it->media << std::endl;
			std::cout << "\n";
			return;
		}
		else {
			++it;
		}
	}
	std::cout << "\n";
	std::cout << "Aluno nao encontrado";
	std::cout << "\n";

}


int main() {
	while (true) {
		int escolha;
		std::cout << "Escolha uma das opcoes:" << std::endl;
		std::cout << "1: Adicionar um aluno" << std::endl;
		std::cout << "2: Remover um aluno" << std::endl;
		std::cout << "3: Editar as notas de um aluno" << std::endl;
		std::cout << "4: Mostrar lista de alunos" << std::endl;
		std::cout << "5: Encerrar o programa" << std::endl;
		std::cout << "Escolha a opcao(1, 2, 3, 4 ou 5): ";
		std::cin >> escolha;
		std::cout << "\n";
		std::cin.ignore();

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
			std::cout << "Programa encerrado.";
			return 0;
		default:
			std::cout << "\nOpcao invalida. Por favor, escolha 1, 2 ou 3.\n" << std::endl;
		}
	}
	return 0;
}