from abc import abstractmethod
from Solucao import Solucao
import random

class AlgoritmoBusca:
    def __init__(self, nome: str, distancias: tuple, solucao_otima: int):
        self.nome = nome
        self.tamanho = len(distancias)
        self.distancias = distancias
        self.solucao_otima = solucao_otima
        self.tempo_limite = 0

    @abstractmethod
    def buscar_solucao(self) -> list[Solucao]:
        pass

    def computar_qualidade_completa(self, ciclo: list) -> int:
        iterator = iter(ciclo)
        elemento_pre = next(iterator)
        qualidade = self.distancias[0][elemento_pre]  # Elemento 0 fixo no início da solução
        for elemento in iterator:
            qualidade += self.distancias[elemento_pre][elemento]
            elemento_pre = elemento
        qualidade += self.distancias[0][elemento_pre]  # Fechando ciclo
        return qualidade

    def gerar_solucao_inicial_aleatoria(self) -> Solucao:
        ciclo = list(range(1, self.tamanho))  # Elemento 0 fixo na primeira posição
        random.shuffle(ciclo)
        qualidade = self.computar_qualidade_completa(ciclo)
        solucao = Solucao(qualidade, ciclo)
        return solucao
