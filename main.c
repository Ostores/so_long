#include "mlx.h"
#include <stdlib.h>

typedef struct s_asset {
    void    *mlx;
    void    *win;
    void    *img;
    int     img_width;
    int     img_height;
} t_asset;

// Fonction de gestion de la fermeture de la fenêtre
int close_window(t_asset *asset)
{
    mlx_destroy_window(asset->mlx, asset->win);
    exit(0);
    return (0);
}

int main(void)
{
    t_asset asset;

    // Initialisation de la bibliothèque mlx
    asset.mlx = mlx_init();
    if (!asset.mlx)
        return (1);

    // Création de la fenêtre (800x600 ici, vous pouvez ajuster les dimensions)
    asset.win = mlx_new_window(asset.mlx, 800, 600, "Fenêtre avec image");
    if (!asset.win)
        return (1);

    // Charger une image XPM
    asset.img = mlx_xpm_file_to_image(asset.mlx, "asset/sp.xpm", &asset.img_width, &asset.img_height);
    if (!asset.img)
    {
        mlx_destroy_window(asset.mlx, asset.win);
        return (1);
    }

    // Afficher l'image dans la fenêtre, à la position (0, 0)
    mlx_put_image_to_window(asset.mlx, asset.win, asset.img, 0, 0);

    // Gérer la fermeture de la fenêtre
    mlx_hook(asset.win, 17, 0, close_window, &asset);

    // Lancer la boucle principale de la bibliothèque mlx
    mlx_loop(asset.mlx);

    return (0);
}
