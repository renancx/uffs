from Solucao import Solucao
from abc import abstractmethod


class Vizinhanca:
    def __init__(self, nome, distancias, qtd_trocas):
        self.nome = nome
        self.distancias = distancias
        self.qtd_trocas = qtd_trocas
        self.tamanho = len(distancias)

    @abstractmethod
    def computar_qualidade(self, solucao: Solucao, i: int, j: int) -> int:
        pass

    @staticmethod
    @abstractmethod
    def gerar_novo_ciclo(solucao: Solucao, i: int, j: int) -> list:
        pass

    @abstractmethod
    def melhor_vizinho(self, solucao: Solucao, tabu: set, temperatura:float) -> Solucao:
        pass

    @abstractmethod
    def primeiro_vizinho_melhor(self, solucao: Solucao, tabu: set) -> Solucao:
        pass
