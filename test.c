/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 02:25:22 by mjadid            #+#    #+#             */
/*   Updated: 2024/09/13 05:08:00 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

# define NC "\e[0m"
# define YELLOW "\e[1;33m"

// thread_routine is the function the thread invokes right after its
// creation. The thread ends at the end of this function.
void *thread_routine(void *data)
{
 pthread_t tid;

 // The pthread_self() function provides
 // this thread's own ID.
 tid = pthread_self();
 printf("%sThread [%lu]: The heaviest burden is to exist without living.%s\n",
  YELLOW, (unsigned long)tid, NC);
 return (NULL); // The thread ends here.
}

int main(void)
{
 pthread_t tid1; // First thread's ID
 pthread_t tid2; // Second thread's ID

 // Creating the first thread that will go
 // execute its thread_routine function.
 pthread_create(&tid1, NULL, thread_routine, NULL);
 printf("Main: Created first thread [%lu]\n", (unsigned long)tid1);
 // Creating the second thread that will also execute thread_routine.
 pthread_create(&tid2, NULL, thread_routine, NULL);
 printf("Main: Created second thread [%lu]\n", (unsigned long)tid2);
 // The main thread waits for the new threads to end
 // with pthread_join.
 pthread_join(tid1, NULL);
 printf("Main: Joining first thread [%lu]\n", (unsigned long)tid1);
 pthread_join(tid2, NULL);
 printf("Main: Joining second thread [%lu]\n", (unsigned long)tid2);
 return (0);
}




