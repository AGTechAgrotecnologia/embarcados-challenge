Os 7 erros observados foram:

    1° - Na função "aumentarRpm" havia uma verificação de RPM utilizando uma variável incorreta. Estava utilizando-se a "rpms_init" e o correto é utilizar a "rpm_init".

    2° - Na função "diminuirRpm" havia uma comparação incorreta de RPM menor que -1.000, o que possibilitava uma instrução incorreta para o motor operar com RPM negativo. Foi corrigida alterando esse valor para 0.

    3° - Na função "diminuirRpm" também havia uma estrutura de repetição incorreta, o que fazia com que o sistema entrasse em um loop infinito sempre que aquela condição era atendida. A estrutura de repetição foi removida.

    4° - Ainda na função "diminuirRpm" havia uma comparação incorreta de RPM maior que 100.000, o que possibilitava que o motor operasse para além do seu limite. O valor foi corrigido para 10.000.

    5° - Na função "aumentarRpmCarro" é preciso verificar se a solicitação de aumento não excede o limite máximo suportado antes de realizar atribuição de valor a variável "rpmAtual_int".

    6° - Na função "diminuirRpmCarro" é preciso verificar se a solicitação de redução não é inferior ao limite mínimo suportado antes de realizar atribuição de valor a variável "rpmAtual_int".

    7° - Na função "exibirRegistros" havia um condicional que limitava a exibição dos registros para somente 4 deles, este condicional foi removido.