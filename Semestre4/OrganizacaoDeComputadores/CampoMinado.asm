#Integrantes: João Vitor Betiatto & Renan Carlos Loewenstein 

		.data
campo:			.space		576   # esta versão suporta campo de até 12 x 12 posições de memória
campoV:			.space		576	#mastriz que será vista pelo usuário
salva_S0:		.word		0
salva_ra:		.word		0
salva_ra1:		.word		0
bandeiraV:		.word 		-2


		  


SelOito:  .string		"\n1) Selecionar tamanho 8x8"
SelDez:	  .string		"\n2) Selecionar tamanho 10x10"
SelDoze:  .string		"\n3) Selecionar tamanho 12x12"
Sair:	  .string		"\n4)sair \n"
erroo:    .string		"\nO número digitado é inválido\n"
Perdeuu:  .string		"\nVocê Perdeu! Mais sorte na próxima vez"
Ganhouu:  .string		"\n Parabéns! você ganhou!!"

jogada:   .string		"\n1) Para fazer uma jogada"
flag:	  .string               "\n2) Colocar Bandeira\n"
Colunas:   .string		"0  1  2  3  4  5  6  7  8  9 10 11\n"
Linhas:   .string		"0\n  1\n  2\n  3\n  4\n  5\n  6\n  7\n  8\n  9\n  10\n  11\n  12\n"


barra:	  .string		"#"
branco:	  .string		" "
linha:	  .string		"\n"
flag1:	  .string		"F"
zerou:  .string			"0"
um:  .string			"1"
dois:  .string			"2"
três:  .string			"3"
quatro:  .string		"4"
cinco:  .string			"5"
seis:  .string			"6"
sete:  .string			"7"
oito:  .string			"8"




Nlinha:   .string		"\nInsira numero da linha:  "
Ncoluna:  .string               "Insira numero da coluna: "

 .text

main1:

	li a2,1
	li a3,2
	li a4,3
	li a5,4

        la  a0, SelOito
	li  a7, 4 
	ecall
	la  a0, SelDez
	li  a7, 4 
	ecall
	la  a0, SelDoze
	li  a7, 4 
	ecall
	la  a0, Sair
	li  a7, 4 
	ecall
	
	li a7, 5
    	ecall
    	
    	beq a0,a2,somaoito
    	beq a0,a3,somadez
    	beq a0,a4,somadoze
    	beq a0,a5,fim

		                                                                
        li s2,3
        li s1,1
        li s3,7
        li s3,8
        
        bgt a0,s2,erro
        blt a0,s1,erro
        beq a0,s3,erro
        beq a0,s4,erro
        

somaoito:
	li s0,8
	j imprime

somadez:
	li s0,10
	j imprime
	
somadoze:
	li s0,12
        j imprime

erro: 

	la a0, erroo	# Carrega a mensagem errobandeira, que indica que não é possível colocar uma bandeira na posição desejada
	li a7, 4		# Imprime a mensagem
	ecall
	j main1
        
imprime:
	main:
	la 	a0, campo	# endereço inicial do campo
	add	a1, zero, s0	# quantidade de linhas do campo
	jal 	INSERE_BOMBA
	nop
	
	jal conta_bom 	#pula para a função que ira contar quantas bombas tem ao redor
	jal 	co1                 #função que enche matriz vista pelo usuário com -1
	addi tp,a4,0
	li t0,1
	li a1,0
	mul a1,s0,s0
	sub tp,a1,t0
	li a1,0
	li t0,0
	li t2,0
	li t1,0
	li a2,0
	li a3,4
	li a4,0
	add a1,a1,s0 #quando vai parar(linha e coluna)
	
	mul a1,a1,a3
	addi a1,a1,1 #adiciona 1 no endereço para passar por todos os elementos.
	
	inicio:
		la  a0, Colunas
		li  a7, 4 
		ecall
				
		beq a6,tp,ganhou
		la s5,campoV
		li a4,0
		li a2,0
		add a2,a2,s0
		li t1,0 # usado para guardar posição numero
		li t2, -1
		li t3, -2 # usado para flag
		li t4,0
		li s10, 0
		li s1, 1
		li s2, 2
		li s3, 3
		li s4, 4
		li s6, 5
		li s7, 6
		li s8, 7
		li s9, 8
		li t4,0
		loop8:
			beq a4,s0,end
			beq t4,a2,pulaL
			lw t1, 0(s5)
			beq t1,t2,ImpHash #se o valor for igual a -1 desvia para imprime hashtag
			beq t1,s10,Imp0
			beq t1,s1,Imp1
			beq t1,s2,Imp2
			beq t1,s3,Imp3
			beq t1,s4,Imp4
			beq t1,s6,Imp5
			beq t1,s7,Imp6
			beq t1,s8,Imp7
			beq t1,s9,Imp8
			beq t1, t3,ImpFlag
			
			
		ImpHash:
		
			la  a0, barra	#imprime valor solicitado
			li  a7, 4 
			ecall
	
			la  a0, branco	#espaço em branco
			li  a7, 4 
			ecall
			la  a0, branco
			li  a7, 4 
			ecall
			add s5,s5,s4 	
			addi t1,t1,1	#adiciona ao contador
			addi t4,t4,1 
			j loop8
			
		Imp0:
		
			la  a0, zerou
			li  a7, 4 
			ecall
	
			la  a0, branco
			li  a7, 4 
			ecall
			la  a0, branco
			li  a7, 4 
			ecall
			add s5,s5,s4
			addi t1,t1,1
			addi t4,t4,1 
			j loop8
			
		Imp1:
		
			la  a0, um
			li  a7, 4 
			ecall
	
			la  a0, branco
			li  a7, 4 
			ecall
			la  a0, branco
			li  a7, 4 
			ecall
			add s5,s5,s4
			addi t1,t1,1
			addi t4,t4,1 
			j loop8
			
		Imp2:
		
			la  a0, dois
			li  a7, 4 
			ecall
	
			la  a0, branco
			li  a7, 4 
			ecall
			la  a0, branco
			li  a7, 4 
			ecall
			add s5,s5,s4
			addi t1,t1,1
			addi t4,t4,1 
			j loop8
	
		Imp3:
		
			la  a0, três
			li  a7, 4 
			ecall
	
			la  a0, branco
			li  a7, 4 
			ecall
			la  a0, branco
			li  a7, 4 
			ecall
			add s5,s5,s4
			addi t1,t1,1
			addi t4,t4,1 
			j loop8
			
		Imp4:
		
			la  a0, quatro
			li  a7, 4 
			ecall
	
			la  a0, branco
			li  a7, 4 
			ecall
			la  a0, branco
			li  a7, 4 
			ecall
			add s5,s5,s4
			addi t1,t1,1
			addi t4,t4,1 
			j loop8
			
		Imp5:
		
			la  a0, cinco
			li  a7, 4 
			ecall
	
			la  a0, branco
			li  a7, 4 
			ecall
			la  a0, branco
			li  a7, 4 
			ecall
			add s5,s5,s4
			addi t1,t1,1
			addi t4,t4,1 
			j loop8
			
		Imp6:
		
			la  a0, seis
			li  a7, 4 
			ecall
	
			la  a0, branco
			li  a7, 4 
			ecall
			la  a0, branco
			li  a7, 4 
			ecall
			add s5,s5,s4
			addi t1,t1,1
			addi t4,t4,1 
			j loop8
			
		Imp7:
		
			la  a0, sete
			li  a7, 4 
			ecall
	
			la  a0, branco
			li  a7, 4 
			ecall
			la  a0, branco
			li  a7, 4 
			ecall
			add s5,s5,s4
			addi t1,t1,1
			addi t4,t4,1 
			j loop8

		Imp8:
		
			la  a0, oito
			li  a7, 4 
			ecall
	
			la  a0, branco
			li  a7, 4 
			ecall
			la  a0, branco
			li  a7, 4 
			ecall
			add s5,s5,s4
			addi t1,t1,1
			addi t4,t4,1 
			j loop8

		ImpFlag:
		
			la  a0, flag1
			li  a7, 4 
			ecall
	
			la  a0, branco
			li  a7, 4 
			ecall
			la  a0, branco
			li  a7, 4 
			ecall
			add s5,s5,s4
			addi t1,t1,1
			addi t4,t4,1 
			j loop8
	
		pulaL:
			
			la  a0, linha
			li  a7, 4 
			ecall
			li t4,0
			addi a4,a4,1
			j loop8
end: 
	j menu_jogadas
	nop
	
menu_jogadas:
	
	la  a0, jogada
	li  a7, 4 
	ecall
	
	la  a0, flag
	li  a7, 4 
	ecall
	
	li a7, 5
    	ecall
    	
    	li a2,1
    	li a3,2
    	beq a0,a2,abrir
    	beq a0,a3,bandeira
    	
    	abrir:
    	
		la  a0,Nlinha
		li  a7, 4 
		ecall
		
		li a7, 5
    		ecall
    	
    		li t1,0
    		add t1,t1,a0
    	    	
    		la  a0,Ncoluna
		li  a7, 4 
		ecall
	
		li a7, 5
    		ecall
    	
    		li t2,0
    		add t2,t2,a0
    		
    		j abre_pos
    	
    	
    	bandeira:
    	
   		la  a0,Nlinha
		li  a7, 4 
		ecall
		
		li a7, 5
    		ecall
    	
    		li t1,0
    		add t1,t1,a0
    	
    	
    		la  a0,Ncoluna
		li  a7, 4 
		ecall
	
		li a7, 5
    		ecall
    		

    		li t2,0
    		add t2,t2,a0
    		
    		j imprime_band
    		
    		############### COMECA IMPRIME BANDEIRA
    		
    imprime_band:
	mainB:
	la 	s5, campoV	# endereço inicial do campo
	add	a1, zero, s0	# quantidade de linhas do campo
	la s1,bandeiraV #bandeira valor
	li s2,0			#vai guardar a posição do campo visivel
	li a3,0
	mul a3,s0,t1
	add a3,a3,t2 #guarda em a3 o endereço de jogada.
	#multiplicando valor do endereço por 4	
	add t0,a3,a3
	add t0,t0,t0
	#adciona a posição no vetor
	add s5,s5,t0
	li t0,0
	li s8,0
	li s9,0
		lw s2,0(s1)
		sw s2, 0(s5)
		j inicio
    	########################
    	   	
abre_pos:
	la 	a0, campo
	la s5,campoV
	add	a1, zero, s0	# quantidade de linhas do campo
	li s1,0			#vai guardar a posição do campo real
	li s2,0			#vai guardar a posição do campo visivel
	li a3,0
	mul a3,s0,t1
	add a3,a3,t2 #guarda em a3 o endereço de jogada.
	#multiplicando valor do endereço por 4	
	add t0,a3,a3
	add t0,t0,t0
	#adciona a posição no vetor
	add a0,a0,t0
	add s5,s5,t0
	li t0,0
	li s8,0
	li s9,0
	li s10, 9 # marcão, o que começa com b, termina com a e todo homem gosta? 
	
	ver_bomba: #aqui começa o loop para verificar se tem bomba na posição/////////////////////
	
		lw  s8,0(a0)
		#verifica se é bomba, se for perde, se não continua.
		beq s8,s10, perdeu
		j imprime_posJ
	
	imprime_posJ:
		lw s2,0(a0)
		sw s2, 0(s5)
		addi a6,a6,1
		j inicio
		
	
	######################	
		
	
	
	perdeu:
		la  a0, Perdeuu
		li  a7, 4 
		ecall
		j fim
		
	
	
	
	
	
	
	
	
	
#-------------------------------------------------------------------------------------------------------------------------

INSERE_BOMBA:
		la 	a0,campo
		la	t0, salva_S0
		sw  	s0, 0 (t0)		# salva conteudo de s0 na memoria
		la	t0, salva_ra
		sw  	ra, 0 (t0)		# salva conteudo de ra na memoria
		
		add 	t0, zero, a0		# salva a0 em t0 - endereço da matriz campo
		add 	t1, zero, a1		# salva a1 em t1 - quantidade de linhas 

QTD_BOMBAS:
		li a4, 15
		add 	t2, zero, a4 		# seta para 15 bombas	
		add 	t3, zero, zero 	# inicia contador de bombas com 0
		addi 	a7, zero, 30 		# ecall 30 pega o tempo do sistema em milisegundos (usado como semente
		ecall 				
		add 	a1, zero, a0		# coloca a semente em a1
INICIO_LACO:
		beq 	t2, t3, FIM_LACO
		add 	a0, zero, t1 		# carrega limite para %	(resto da divisão)
		jal 	PSEUDO_RAND
		add 	t4, zero, a0		# pega linha sorteada e coloca em t4
		add 	a0, zero, t1 		# carrega limite para % (resto da divisão)
   		jal 	PSEUDO_RAND
		add 	t5, zero, a0		# pega coluna sorteada e coloca em t5

###############################################################################
# imprime valores na tela (para debug somente) - retirar comentarios para ver
#	
#		li	a7, 4		# mostra texto "Posicao: "
#		la	a0, posicao
#		ecall
#		
#		li	a7, 1		
#		add 	a0, zero, t3 	# imprime quantidade ja sorteada
#		ecall		
#
#		li	a7, 4		# imrpime :
#		la	a0, dois_pontos
#		ecall
#
#		li	a7, 1
#		add 	a0, zero, t4 	# imprime a linha sorteada	
#		ecall
#		
#		li	a7, 4		# imrpime espaço
#		la	a0, espaco
#		ecall	
#			
#		li	a7, 1
#		add 	a0, zero, t5 	# imprime coluna sorteada
#		ecall
#		
##########################################################################	

LE_POSICAO:	
		mul  	t4, t4, t1
		add  	t4, t4, t5  		# calcula (L * tam) + C
		add  	t4, t4, t4  		# multiplica por 2
		add  	t4, t4, t4  		# multiplica por 4
		add  	t4, t4, t0  		# calcula Base + deslocamento
		lw   	t5, 0(t4)   		# Le posicao de memoria LxC
VERIFICA_BOMBA:		
		addi 	t6, zero, 9		# se posição sorteada já possui bomba
		beq  	t5, t6, PULA_ATRIB	# pula atribuição 
		sw   	t6, 0(t4)		# senão coloca 9 (bomba) na posição
		addi 	t3, t3, 1		# incrementa quantidade de bombas sorteadas
PULA_ATRIB:
		j	INICIO_LACO

FIM_LACO:					# recupera registradores salvos
		la	t0, salva_S0
		lw  	s0, 0(t0)		# recupera conteudo de s0 da memória
		la	t0, salva_ra
		lw  	ra, 0(t0)		# recupera conteudo de ra da memória		
		jr 	ra			# retorna para funcao que fez a chamada
		
##################################################################
# PSEUDO_RAND
# função que gera um número pseudo-randomico que será
# usado para obter a posição da linha e coluna na matriz
# entrada: a0 valor máximo do resultado menos 1 
#             (exemplo: a0 = 8 resultado entre 0 e 7)
#          a1 para o número pseudo randomico 
# saida: a0 valor pseudo randomico gerado
#################################################################
#int rand1(int lim, int semente) {
#  static long a = semente; 
#  a = (a * 125) % 2796203; 
#  return (|a % lim|); 
# }  

PSEUDO_RAND:
		addi t6, zero, 125  		# carrega constante t6 = 125
		lui  t5, 682			# carrega constante t5 = 2796203
		addi t5, t5, 1697 		# 
		addi t5, t5, 1034 		# 	
		mul  a1, a1, t6			# a = a * 125
		rem  a1, a1, t5			# a = a % 2796203
		rem  a0, a1, a0			# a % lim
		bge  a0, zero, EH_POSITIVO  	# testa se valor eh positivo
		addi s2, zero, -1           	# caso não 
		mul  a0, a0, s2		    	# transforma em positivo
EH_POSITIVO:	
		ret				# retorna em a0 o valor obtido
		
		
conta_bom:
	la a0,campo
	li a1,0#parada
	li t0,0 # endereço backup
	li t2,0 # contador
	li t1,0 #baiano
	li t3,4 # valor 4 para facilitar contas
	li t4,0
	li t5,9 # marcão, o que começa com b, termina com a e todo homem gosta? 
	li t6,0 # condição de parada
	li a2,0
	add t0,a0,t0 # salva endereço inicial em t0 
	add a2,a2,s0
	mul a2,a2,t3
	add a1,a1,s0 #quando vai parar(linha e coluna) S0 tem o tamanho
	mul a1,a1,a1
	laco1:		#primeiro laco, conta as posições.
		beq t6,a1, terminoCount #quando foi tudo vaza
		li t2,0 # zera t2(de novo) para ele ter o valor de bombas para cada caso
		addi a0,t0,0
		lw t4,0(a0)
		beq t4,t5,cond9
		laco2: #vai fazer as verificações necessárias
			# ela +1
			add a0,a0,t3
			lw  t4,0(a0)
			bne t4,t5,pula
			addi t2,t2,1
			pula:
				#ela -1
				addi a0,t0,0 #"Reinicia" o valor de a0
				sub a0,a0,t3 #faz as contas neceesárias
				lw t4,0(a0)
				bne t4,t5,pula1 # se não tiver bomba pula, se não segue o fluxo e soma
				addi t2,t2,1
				
				pula1:
				#ela +tam
				addi a0,t0,0
				add a0,a0,a2
				lw t4,0(a0)
				bne t4,t5,pula2
				addi t2,t2,1
				
				pula2:
				#ela +tam + 1
				addi a0,t0,0
				add a0,a0,a2
				add a0,a0,t3
				lw t4,0(a0)
				bne t4,t5,pula3
				addi t2,t2,1
				
				pula3:
				#(ela +tam) - 1
				addi a0,t0,0
				add a0,a0,a2
				sub a0,a0,t3
				lw t4,0(a0)
				bne t4,t5,pula4
				addi t2,t2,1
				
				pula4:
				#ela -tam
				addi a0,t0,0
				sub a0,a0,a2
				lw t4,0(a0)
				bne t4,t5,pula5
				addi t2,t2,1
				
				pula5:
				#(ela -tam) + 1
				addi a0,t0,0
				sub a0,a0,a2
				add a0,a0,t3
				lw t4,0(a0)
				bne t4,t5,pula6
				addi t2,t2,1
				
				pula6:
				#(ela -tam) - 1
				addi a0,t0,0
				sub a0,a0,a2
				sub a0,a0,t3
				lw t4,0(a0)
				bne t4,t5,swap
				addi t2,t2,1
				addi a0,t0,0
				
				swap:
					sw t2, 0(t0)
					add t0,t0,t3
					addi t6,t6,1
					j laco1	
								
					
				cond9:
					add t0,t0,t3
					addi t6,t6,1
					j laco1	
			
		
	
				
	
	terminoCount:
		ret 	

		
co1:
	la s5,campoV # s5 padrão pra visivel assim como a0 para não visivel 
	li a1,0 #parada
	li t1,0 #contador
	li t2,-1 #-1 valor
	add a1,a1,s0
	mul a1,a1,a1 # numero total de linhas para colocar -1
	laco1B:
		beq t1,a1,parou
		sw t2,0(s5)
		addi s5,s5,4
		addi t1,t1,1
		j laco1B
			
		
		
	parou:
		ret

ganhou:
	la  a0, Ganhouu
	li  a7, 4 
	ecall
	j fim
 		
fim: 
	nop
