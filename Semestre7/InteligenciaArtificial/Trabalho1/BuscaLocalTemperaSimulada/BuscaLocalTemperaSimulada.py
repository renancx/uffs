from AlgoritmoBusca import AlgoritmoBusca
from Solucao import Solucao
from Vizinhanca import Vizinhanca
import time

class BuscaLocalTemperaSimulada(AlgoritmoBusca):
    def __init__(self, vizinhanca: Vizinhanca, solucao_otima:int, tipo_resfriamento:int, alpha:float, temperatura:float, solucao:Solucao = None):
        super().__init__("BLTS"+vizinhanca.nome, vizinhanca.distancias, solucao_otima)

        self.alpha = alpha
        self.temperatura = temperatura
        self.vizinhanca = vizinhanca

        self.tipo_resfriamento = tipo_resfriamento  # 0: geométrico, 1: linear

        if tipo_resfriamento == 0:  # Uso de função lambda para definir a função de resfriamento
            self.resfriar = lambda x:x*self.alpha  # Forma geométrica
        else:
            linear = lambda x : x if x > 0 else 0 # Forma linear
            self.resfriar = lambda x: linear(x-self.alpha)
        if solucao is None:
            self.solucao = self.gerar_solucao_inicial_aleatoria() # Gera uma solucao aleatória do arquivo AlgoritmoBusca.py
        else:
            self.solucao = solucao # Recebe uma solução

    def buscar_solucao(self) -> list[Solucao]:  # Retorna uma lista de soluções

        solucao_list = [self.solucao]
        iteracao = self.solucao.iteracao + 1
        melhor_qualidade = self.solucao.qualidade

        # Enquanto o tempo limite não for atingido
        # e a temperatura não for menor que 0.01
        while time.time() < self.tempo_limite:
            self.solucao = self.vizinhanca.melhor_vizinho(self.solucao, set(), self.temperatura)

            if self.solucao.qualidade < melhor_qualidade:
                melhor_qualidade = self.solucao.qualidade
                self.solucao.tempo = time.time() - self.tempo_limite # Tempo de execução
                self.solucao.iteracao = iteracao
                solucao_list.append(self.solucao) # Adiciona a solução na lista
                
                if melhor_qualidade == self.solucao_otima:
                    return solucao_list
            else:
                break

            # Atualiza a temperatura
            iteracao += 1
            # self.temperatura = self.temperatura*self.alpha
            # self.temperatura = self.temperatura - self.alpha
            self.temperatura = self.resfriar(self.temperatura) if self.resfriar(self.temperatura) >= 0.01 else 0
        
        return solucao_list