import random
import numpy as np
from typing import List

from collections import Counter

random.seed(10)

class UE:
    def __init__(self, preamble) -> None:
        self.preamble = preamble;
        self.delay = 0;

def beta_distribution(alpha: float, beta: float, t: int, T: int) -> int:
    return (pow(t, alpha-1)*pow((T-t), beta-1)) / (pow(T, alpha+beta-1)*np.random.beta(alpha, beta))


def initial_UE(nUE: int, total_time: int) -> List:
    ue_list = [[] for _ in range(total_time)]
    for _ in range(nUE):
        # send_time = round(nUE*beta_distribution(3.0, 4.0, random.randrange(0,total_time), total_time)/1000)
        send_time = random.randrange(1,total_time)
        preamble = random.randrange(1,65)
        ue_list[send_time].append(UE(preamble=preamble))
    
    return ue_list

def result(ue_list: List, total_time: int) -> None:
    i = 0
    avg_delay = []
    for t in range(total_time):
        if not ue_list[t]:
            pass
        for ue in ue_list[t]:
            print(f'UE {i+1}\'s delay : {ue.delay}')
            avg_delay.append(ue.delay)
            i+=1

    print("="*30)
    print(sum(avg_delay)/len(avg_delay))

if __name__ == "__main__":
    T = 60000
    ue_list = initial_UE(30000, T)

    for t in range(T):
        # print("Time :",t)
        preamble_dict = dict()
        preamble_list = list()
        preamble_collision_list = list()
        preamble_tx_success_list = list()
        for i, ue in enumerate(ue_list[t]):
            preamble_list.append(ue.preamble)
            if ue.preamble in preamble_dict:
                preamble_dict[ue.preamble].append(i)
            else:
                preamble_dict[ue.preamble] = [i]
            # print(f'UE {i}\'s preamble : {ue.preamble}')

        for i, x in enumerate(Counter(preamble_list).values()):
            if x > 1:
                preamble_collision_list.append(i)
            else:
                preamble_tx_success_list.append(i)

        # if any(1 < x for x in Counter(preamble_list).values()): # preamble 충돌 찾기
        #     print(Counter(preamble_list).values())

        # print(preamble_dict)
        # print(preamble_tx_success_list)
        for x in preamble_tx_success_list: # preamble 충돌이 나지 않은 UE
            # print('SUCCESS')
            # print(preamble_dict[list(preamble_dict.keys())[x]])
            for ue in preamble_dict[list(preamble_dict.keys())[x]]:
                rar = random.randrange(1,6)
                contention_resolution_timer = random.randrange(1,49)
                ue_list[t][ue].delay += rar
                ue_list[t][ue].delay += contention_resolution_timer
                # print('-'*30)


        # print(preamble_collision_list)
        for x in preamble_collision_list: # preamble이 충돌난 UE의 경우
            # print('COLLISION')
            # print(preamble_dict[list(preamble_dict.keys())[x]])
            for ue in preamble_dict[list(preamble_dict.keys())[x]]:
                bo = random.randrange(1,21) # backoff
                ue_list[t][ue].delay += 5
                ue_list[t+bo].append(ue_list[t][ue])
            ue_list[t].clear()
            # print('-'*30)
        
        # if t == 8277:
        #     break
        # print('='*30)
    result(ue_list, T)
    