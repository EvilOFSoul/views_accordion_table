/**
 * Created by Eugeniy on 04.02.2016.
 */
Drupal.behaviors.complexTable = {
    attach: function (context, settings) {
        jQuery('.accordion-row-head').on('dblclick',function() {
            var idClass = jQuery(this).attr('class').split(' ');
            for(var i = 0; i<idClass.length; i++)
            {
                if(idClass[i].indexOf("accordion-row-head-") != -1)
                {
                    idClass = idClass[i];
                    break;
                }
            }
            idClass = '.'+idClass.replace('-head','-body');
            jQuery(idClass,jQuery(this).parent()).toggleClass('hiddenRow');
            return false;
        });
    }
};