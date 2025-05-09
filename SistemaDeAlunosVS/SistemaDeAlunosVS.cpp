#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

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

float calcularMedia() {
	std::cout << "\nAdicione quantas notas desejar (de 0 a 20), a media sera calculada automaticamente.\n"
		<< "Quando ja tiver posto todas as notas, digite C para calcular a media do aluno.\n";

	std::string inputDoUsuario = "";
	int contadorDeNotas = 0;
	float somaDasNotas = 0.0;
	float media = 0.0;

	while (true) {

		std::cout << "Nota " << contadorDeNotas + 1 << ": ";
		std::cin >> inputDoUsuario;
		
		if (inputDoUsuario == "C" || inputDoUsuario == "c") {
			break;
		}

		try {
			float nota = std::stof(inputDoUsuario);
			
			if (nota >= 0.0 && nota <= 20.0) {
				somaDasNotas += nota;
				++contadorDeNotas;
			}
			else {
				std::cout << "\nPor favor, insira uma nota de 0 a 20.\n";
			}
		}
		catch (...) {
			std::cout << "\nEntrada invalida. Por favor digite um numero valido ou C para calcular.\n";
		}
	}
	media = somaDasNotas / contadorDeNotas;
	return media;
}

void adicionar() {

	std::string nome = "";
	float media = 0;

	// Pegar do utilizador os atributos dos alunos
	std::cout << "Nome: ";
	std::getline(std::cin, nome);

	//Chama função que calcula a media e atribui essa media à variavel
	media = calcularMedia();

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

			//Chama função que calcula a media e atribui essa media à variavel
			float novaMedia = calcularMedia();

			it->media = novaMedia;
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
	// imprimir apenas uma casa decimal 
	std::cout << std::fixed << std::setprecision(2);

	bool controleDeCiclo = true;
	while (controleDeCiclo) {
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
		case 5: {
			controleDeCiclo = false;
			std::cout << "Programa encerrado.";
			break;
		}
		default:
			std::cout << "\nOpcao invalida. Por favor, escolha uma das opcoes disponiveis.\n" << std::endl;
		}
	}
	return 0;
}