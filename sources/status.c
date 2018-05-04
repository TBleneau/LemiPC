/*
** EPITECH PROJECT, 2018
** status.c
** File description:
** Created by Thomas BLENEAU
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include "lemipc.h"

int sem_unlock(t_lemi *lemi)
{
	struct sembuf buf;

	buf.sem_num = 0;
	buf.sem_flg = 0;
	buf.sem_op = 1;
	semop(lemi->sem_key, &buf, 1);
	return (0);
}

int sem_lock(t_lemi *lemi)
{
	struct sembuf buf;

	buf.sem_num = 0;
	buf.sem_flg = 0;
	buf.sem_op = -1;
	if (semop(lemi->sem_key, &buf, 1) == -1)
		sem_unlock(lemi);
	return (0);
}
