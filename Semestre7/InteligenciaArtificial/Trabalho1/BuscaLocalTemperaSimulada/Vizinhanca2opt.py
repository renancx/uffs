from Vizinhanca import Vizinhanca
from Solucao import Solucao
from math import e,inf
from random import random,seed
from time import time


class Vizinhanca2opt(Vizinhanca):
    def __init__(self, distancias: tuple):
        super().__init__("2opt", distancias, 2)

    def computar_qualidade(self, solucao: Solucao, i: int, j: int) -> int:
        qualidade = solucao.qualidade
        elemento_pre_i, elemento_i, elemento_pos_i, elemento_pre_j, elemento_j, elemento_pos_j \
            = solucao.retornar_elementos(i, j)
        # i sempre < j
        qualidade += - self.distancias[elemento_i][elemento_pre_i] - self.distancias[elemento_j][elemento_pos_j] \
            + self.distancias[elemento_i][elemento_pos_j] + self.distancias[elemento_j][elemento_pre_i]
        return qualidade

    @staticmethod
    def gerar_novo_ciclo(solucao: Solucao, i: int, j: int) -> list:
        return solucao.ciclo[:i] + list(reversed(solucao.ciclo[i:j + 1])) + solucao.ciclo[j + 1:]

    def melhor_vizinho(self, solucao: Solucao, tabu: set, temperatura:float) -> Solucao:
        melhor_qualidade = inf
        imelhor = -1
        jmelhor = -1
        seed(time())
        for i in range(self.tamanho-1):
            if solucao.ciclo[i] not in tabu:
                for j in range(i+1, self.tamanho-1):
                    if solucao.ciclo[j] not in tabu:
                        qualidade = self.computar_qualidade(solucao, i, j)
                        if qualidade < melhor_qualidade:
                            melhor_qualidade = qualidade
                            imelhor = i
                            jmelhor = j
                        elif temperatura > 0:
                            deltaC = lambda x:(x/melhor_qualidade)-1
                            calculaAceite = lambda x:e ** ((-1 * deltaC(x))/temperatura)
                            if random() <= calculaAceite(qualidade):
                                melhor_qualidade = qualidade
                                imelhor = i
                                jmelhor = j
        return Solucao(melhor_qualidade, self.gerar_novo_ciclo(solucao, imelhor, jmelhor), solucao.ciclo[imelhor], solucao.ciclo[jmelhor])

    def primeiro_vizinho_melhor(self, solucao: Solucao, tabu: set) -> Solucao:
        melhor_qualidade = solucao.qualidade
        for i in range(self.tamanho-1):
            if i not in tabu:
                for j in range(i + 1, self.tamanho-1):
                    if j not in tabu:
                        qualidade = self.computar_qualidade(solucao, i, j)
                        if qualidade < melhor_qualidade:
                            return Solucao(qualidade, self.gerar_novo_ciclo(solucao, i, j), i, j)
        return solucao

    # Para a primeira chamada da função usar i_inicial = 0 e j_inicial = 1
    def proximo_vizinho(self, solucao: Solucao, i_inicial: int, j_inicial: int) -> Solucao:
        for i in range(i_inicial, self.tamanho-1):
            for j in range(j_inicial, self.tamanho-1):
                qualidade = self.computar_qualidade(solucao, i, j)
                return Solucao(qualidade, self.gerar_novo_ciclo(solucao, i, j), i, j)
        return solucao
