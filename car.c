#include "header.h"
/* funktions definitioner */

struct car_vtable* car_vtable_ptr_get(void);
/********************************************************************************
* car_init: Initierar ny bil.
*
*              self: Pekare till bilen som ska initieras.
*              brand: Bilmärke.
*              model: Bilmodell.
*              color: Färg på bilen.
*              year: Året den tillverkades.
*              transmission: Växellåda.
*
********************************************************************************/
void car_init(car* self,
			  char* brand,
			  char* model,
		  	  char* color,
			  unsigned int year,
			  enum car_transmission transmission)
{
	self->brand = brand;
	self->model = model;
	self->color = color;
	self->year_of_launch = year;
	self->transmission = transmission;
	self->vptr = car_vtable_ptr_get();

	return;
}
/********************************************************************************
* car_clear: Nollställer bil.
*          - self: Pekare till bilen som ska nollställas.
********************************************************************************/
void car_clear(car* self)
{
	free(self->brand);
	self->brand = 0;
	free(self->model);
	self->model = 0;
	free(self->color);
	self->color = 0;
	self->year_of_launch = 0;
	self->transmission = NONE;

	return;
}
/********************************************************************************
* car_new: Returnerar en pekare till car-objekt, som initieras
*          via funktionen car_init.
********************************************************************************/
car* car_new(char* brand,
	         char* model,
	         char* color,
	         unsigned int year,
	         enum car_transmission transmission)
{
	car* self = malloc(sizeof(car));
	car_init(self, brand, model, color, year, transmission);

	return self;
}
/********************************************************************************
* car_delete: Raderar objekt genom att frigöra minnet.
* *******************************************************************************/
void car_delete(car** self)
{
	car_clear(*self);
	free(*self);
	*self = NULL;
}

/********************************************************************************
* car_print: Skriver ut information om given bil.
*********************************************************************************/
void car_print(car* self,
	FILE* ostream)
{
	if (!ostream) ostream = stdout;

	fprintf(ostream, "Brand: %s\nModel: %s\nColor: %s\nYear of launch: %u\nTransmission: ",
		self->brand, self->model, self->color, self->year_of_launch);
	switch (self->transmission)
	{
	case MANUAL:
		fprintf(ostream, "Manual\n");
		break;
	case AUTOMATIC:
		fprintf(ostream, "Automatic\n");
		break;
	}
	return;
}
/********************************************************************************
* car_change_color: Ändrar bilens färg till en ny färg.
********************************************************************************/
static void car_change_color(car* self,
	                         char* color)
{
	self->color = color;
	return;
}
/********************************************************************************
* car_change_transmission: Ändrar bilens växellåda från manuell till automat
*                          eller vise versa.
********************************************************************************/
static void car_change_transmission(car* self)
{

	if (self->transmission == MANUAL)
	{
		self->transmission = AUTOMATIC;
	}
	else
	{
		self->transmission = MANUAL;
	}
	return;
}
/********************************************************************************
* car_vtable_ptr_get: Returnerar en vtable-pekare. 
********************************************************************************/
static struct car_vtable* car_vtable_ptr_get(void)
{
	static struct car_vtable self =
	{
		.print = &car_print,
		.change_transmission = &car_change_transmission,
		.change_color = &car_change_color
	};

	return &self;
}