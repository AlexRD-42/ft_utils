
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

OPSIZE = 16;
void *
MEMCPY (void *dstpp, const void *srcpp, size_t len)
{
  unsigned long int dstp = (long int) dstpp;
  unsigned long int srcp = (long int) srcpp;

  /* Copy from the beginning to the end.  */

  /* If there not too few bytes to copy, use word copy.  */
  if (len >= OP_T_THRES)
    {
      /* Copy just a few bytes to make DSTP aligned.  */
      len -= (-dstp) % OPSIZ;
      BYTE_COPY_FWD (dstp, srcp, (-dstp) % OPSIZ);

      /* Copy whole pages from SRCP to DSTP by virtual address manipulation,
	 as much as possible.  */

      PAGE_COPY_FWD_MAYBE (dstp, srcp, len, len);

      /* Copy from SRCP to DSTP taking advantage of the known alignment of
	 DSTP.  Number of bytes remaining is put in the third argument,
	 i.e. in LEN.  This number may vary from machine to machine.  */

      WORD_COPY_FWD (dstp, srcp, len, len);

      /* Fall out and copy the tail.  */
    }

  /* There are just a few bytes to copy.  Use byte memory operations.  */
  BYTE_COPY_FWD (dstp, srcp, len);

  return dstpp;
}

#define WORD_COPY_FWD(dst_bp, src_bp, nbytes_left, nbytes)		      \
  do									      \
    {									      \
      if (src_bp % OPSIZ == 0)						      \
	_wordcopy_fwd_aligned (dst_bp, src_bp, (nbytes) / OPSIZ);	      \
      else								      \
	_wordcopy_fwd_dest_aligned (dst_bp, src_bp, (nbytes) / OPSIZ);	      \
      src_bp += (nbytes) & -OPSIZ;					      \
      dst_bp += (nbytes) & -OPSIZ;					      \
      (nbytes_left) = (nbytes) % OPSIZ;					      \
    } while (0)
		
#define WORD_COPY_BWD(dst_ep, src_ep, nbytes_left, nbytes)		      \
  do									      \
    {									      \
      if (src_ep % OPSIZ == 0)						      \
	_wordcopy_bwd_aligned (dst_ep, src_ep, (nbytes) / OPSIZ);	      \
      else								      \
	_wordcopy_bwd_dest_aligned (dst_ep, src_ep, (nbytes) / OPSIZ);	      \
      src_ep -= (nbytes) & -OPSIZ;					      \
      dst_ep -= (nbytes) & -OPSIZ;					      \
      (nbytes_left) = (nbytes) % OPSIZ;					      \
    } while (0)
		
# define PAGE_COPY_FWD_MAYBE(dstp, srcp, nbytes_left, nbytes)		      \
  do									      \
    {									      \
      if ((nbytes) >= PAGE_COPY_THRESHOLD				      \
	  && PAGE_OFFSET ((dstp) - (srcp)) == 0)			      \
	{								      \
	  /* The amount to copy is past the threshold for copying	      \
	     pages virtually with kernel VM operations, and the		      \
	     source and destination addresses have the same alignment.  */    \
	  size_t nbytes_before = PAGE_OFFSET (-(dstp));			      \
	  if (nbytes_before != 0)					      \
	    {								      \
	      /* First copy the words before the first page boundary.  */     \
	      WORD_COPY_FWD (dstp, srcp, nbytes_left, nbytes_before);	      \
	      assert (nbytes_left == 0);				      \
	      nbytes -= nbytes_before;					      \
	    }								      \
	  PAGE_COPY_FWD (dstp, srcp, nbytes_left, nbytes);		      \
	}								      \
    } while (0)


	#define PAGE_COPY_THRESHOLD		(16384)

	#define PAGE_SIZE		__vm_page_size
	#define PAGE_COPY_FWD(dstp, srcp, nbytes_left, nbytes)			      \
	  ((nbytes_left) = ((nbytes)						      \
				- (__vm_copy (__mach_task_self (),			      \
					  (vm_address_t) srcp, trunc_page (nbytes),   \
					  (vm_address_t) dstp) == KERN_SUCCESS	      \
				   ? trunc_page (nbytes)				      \
				   : 0)))