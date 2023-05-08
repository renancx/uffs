from AlgoritmoBusca import AlgoritmoBusca
from BuscaConstrutivaGulosa import BuscaConstrutivaGulosa
from Vizinhanca import Vizinhanca

class BuscaHibridaGulosoTemperaSimulada(AlgoritmoBusca):
    def __init__(self, vizinhanca: Vizinhanca, solucao_otima:int, tipo_resfriamento:int, alpha:float, temperatura:float):
        super().__init__("BLTS"+vizinhanca.nome, vizinhanca.distancias, solucao_otima)
        self.temperatura = temperatura
        self.alpha = alpha
        if tipo_resfriamento == 0:
            self.resfriar = lambda x:x*self.alpha
        else:
            linear = lambda x : x if x > 0 else 0
            self.resfriar = lambda x: linear(x-self.alpha)
        self.solucao = None
        
    def gerar_solucao_inicial(self):
        guloso = BuscaConstrutivaGulosa(self.distancias, self.solucao_otima)
        guloso.tempo_limite = self.tempo_limite
        solucao_inicial = guloso.buscar_solucao()[0]
        return solucao_inicial
        
    def buscar_solucao(self):
        self.solucao = self.gerar_solucao_inicial()
        # implementação do algoritmo de busca local por tempera simulada
        # ...
