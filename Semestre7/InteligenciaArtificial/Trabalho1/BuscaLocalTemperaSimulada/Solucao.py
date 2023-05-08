class Solucao:
    def __init__(self, qualidade: int, ciclo: list, i_movimento: int = 0, j_movimento: int = 0):
        self.qualidade = qualidade
        self.ciclo = ciclo
        self.i_movimento = i_movimento
        self.j_movimento = j_movimento
        self.tempo = 0
        self.iteracao = 0

    def __str__(self):
        return "Ciclo: "+str([0]+self.ciclo)+"\nQualidade: "+str(self.qualidade)

    def retornar_elementos(self, i: int, j: int) -> tuple[int, int, int, int, int, int]:
        elemento_i = self.ciclo[i]
        elemento_j = self.ciclo[j]
        if i == 0:
            elemento_pre_i = 0  # Elemento 0 Fixo na Primeira Posição
        else:
            elemento_pre_i = self.ciclo[i - 1]
        if j == 0:
            elemento_pre_j = 0  # Elemento 0 Fixo na Primeira Posição
        else:
            elemento_pre_j = self.ciclo[j - 1]
        if i == len(self.ciclo) - 1:
            elemento_pos_i = 0  # Elemento 0 Fixo na Primeira Posição
        else:
            elemento_pos_i = self.ciclo[i + 1]
        if j == len(self.ciclo) - 1:
            elemento_pos_j = 0  # Elemento 0 Fixo na Primeira Posição
        else:
            elemento_pos_j = self.ciclo[j + 1]
        return elemento_pre_i, elemento_i, elemento_pos_i, elemento_pre_j, elemento_j, elemento_pos_j
