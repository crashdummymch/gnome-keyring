/* 
 * gnome-keyring
 * 
 * Copyright (C) 2008 Stefan Walter
 * 
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *  
 * You should have received a copy of the GNU Lesser General Private
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.  
 */

#ifndef __GCK_PRIVATE_KEY_H__
#define __GCK_PRIVATE_KEY_H__

#include <glib-object.h>

#include "gck-key.h"
#include "gck-sexp.h"

#define GCK_TYPE_PRIVATE_KEY               (gck_private_key_get_type ())
#define GCK_PRIVATE_KEY(obj)               (G_TYPE_CHECK_INSTANCE_CAST ((obj), GCK_TYPE_PRIVATE_KEY, GckPrivateKey))
#define GCK_PRIVATE_KEY_CLASS(klass)       (G_TYPE_CHECK_CLASS_CAST ((klass), GCK_TYPE_PRIVATE_KEY, GckPrivateKeyClass))
#define GCK_IS_PRIVATE_KEY(obj)            (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GCK_TYPE_PRIVATE_KEY))
#define GCK_IS_PRIVATE_KEY_CLASS(klass)    (G_TYPE_CHECK_CLASS_TYPE ((klass), GCK_TYPE_PRIVATE_KEY))
#define GCK_PRIVATE_KEY_GET_CLASS(obj)     (G_TYPE_INSTANCE_GET_CLASS ((obj), GCK_TYPE_PRIVATE_KEY, GckPrivateKeyClass))

typedef struct _GckPrivateKey GckPrivateKey;
typedef struct _GckPrivateKeyClass GckPrivateKeyClass;
typedef struct _GckPrivateKeyPrivate GckPrivateKeyPrivate;
    
struct _GckPrivateKey {
	GckKey parent;
	GckPrivateKeyPrivate *pv;
};

struct _GckPrivateKeyClass {
	GckKeyClass parent_class;
};

GType                      gck_private_key_get_type               (void);

GckPrivateKey*             gck_private_key_new                    (void);

void                       gck_private_key_store_private          (GckPrivateKey *self, 
                                                                   GckSexp *sexp, 
                                                                   guint num_uses);               

#endif /* __GCK_PRIVATE_KEY_H__ */