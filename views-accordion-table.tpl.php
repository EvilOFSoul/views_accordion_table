<?php
/**
 * Created by PhpStorm.
 * User: Eugeniy
 * Date: 26.01.2016
 * Time: 19:51
 */
?>
<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
    <?php if (!empty($title)) : ?>
        <caption><?php print $title; ?></caption>
    <?php endif; ?>
    <thead>
    <tr>
        <?php foreach ($header as $field => $label): ?>
            <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?>>
                <?php print $label; ?>
            </th>
        <?php endforeach; ?>
    </tr>
    </thead>
    <tbody>
    <?php foreach ($rows as $count => $row): ?>
        <tr class="<?php print implode(' ', $row_classes[$count]); ?>">
            <?php foreach ($row as $field => $content): ?>
                <td <?php if ($field_classes[$field][$count]) { print 'class="'. $field_classes[$field][$count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$count]); ?>>
                    <?php print $content; ?>
                </td>
            <?php endforeach; ?>
        </tr>
        <?php if(!empty($collapsible_rows[$count])): ?>
            <tr class="accordion-row-body-<?php echo $count; ?> hiddenRow">
                <td colspan="<?php print count($row); ?>">
                    <?php foreach($collapsible_rows[$count] as $collapsible_field): ?>
                        <div><?php print $collapsible_field; ?></div>
                    <?php endforeach; ?>
                </td>
            </tr>
        <?php endif; ?>
    <?php endforeach; ?>
    </tbody>
</table>
