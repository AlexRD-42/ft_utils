// __always_inline
// void	put_argb(t_img *img, uint32_t x, uint32_t y, uint32_t argb)
// {
//     t_argb			*dst;
// 	const t_argb	src = {.argb = argb};

// 	dst = (t_argb *) (img->data + y * img->width + x);
// 	dst->r += (int32_t) (src.r - dst->r) * src.a >> 8; 
// 	dst->g += (int32_t) (src.g - dst->g) * src.a >> 8; 
// 	dst->b += (int32_t) (src.b - dst->b) * src.a >> 8; 
// 	dst->a += (int32_t) (0x0FF - dst->a) * src.a >> 8;
// }