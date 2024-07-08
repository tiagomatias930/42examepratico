# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    auto_correc_program.sh                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timatias <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 02:00:55 by timatias          #+#    #+#              #
#    Updated: 2024/07/08 02:00:58 by timatias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FILE="../../rendu/$2/$1"

# echo ""

tmp=""
timeout=1

if [ -e .system/grading/traceback ]; then
    rm .system/grading/traceback;
fi

cd .system/grading
gcc -o source "$1"
./source "${@:3}" | cat -e > sourcexam       # TESTE
rm -f source
{
gcc -o final "$FILE"
} 2>.dev
{
./final "${@:3}" | cat -e > finalexam &       # TESTE
PID=$!
} &>/dev/null

# loop de 1 segundo por 20 segundos
for i in {1..20}
do
    sleep 1
    # se o PID não estiver em execução, então saia
    # se i for 5, 10, 15, 19 então ecoa "esperando..."
    if [ $i -eq 5 ] || [ $i -eq 10 ] || [ $i -eq 15 ] || [ $i -eq 19 ]; then
        echo "esperando..."
    fi
    if ! ps -p $PID > /dev/null
    then
        timeout=0
        break
    fi
done

DIFF=$(diff sourcexam finalexam)
if [ "$DIFF" != "" ]
then
        echo "----------------8<-------------[ INÍCIO DO TESTE " >> traceback
        printf "        💻 TESTE\n./a.out " >> traceback
        # imprime todos os argumentos, começando pelo 3º
        for i in "${@:3}"
        do
            printf "\"$i\" " >> traceback
        done
        printf "\n        🔎 SUA SAÍDA:\n" >> traceback
        cat finalexam >> traceback
        if [ $timeout -eq 1 ]
        then
        printf "   ❌ TEMPO ESGOTADO\n" >> traceback
        elif [ -e final ]
        then
        printf "        🗝 SAÍDA ESPERADA:\n" >> traceback
        cat sourcexam >> traceback
        else
        printf "\n"
        echo "$(cat .dev)" >> traceback
        rm .dev
        printf "\n        ❌ ERRO DE COMPILAÇÃO\n" >> traceback
        fi
        echo "----------------8<------------- FIM DO TESTE ]" >> traceback
fi
{
rm final
rm finalexam
rm sourcexam
} &>/dev/null
cd ../..
